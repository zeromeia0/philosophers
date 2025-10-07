/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_thread_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:12:28 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/07 14:20:29 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <bits/types/struct_timeval.h>
#include <sys/time.h>

t_time	get_current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);                                    
		/* tz is almost always NULL */
	return (t_time)(tv.tv_sec * 1000ULL + tv.tv_usec / 1000ULL);
		/*  milliseconds */
	/* 	1000ULL -> converts to miliss
		tv.tv_usec / 1000ULL -> convert microseconds to miliseconds
		time_t tv_sec;   // seconds since Jan 1, 1970 (the Unix epoch)
	suseconds_t tv_usec; // microseconds (millionths of a second) */
}

void	get_time_values(t_philos *philo, char **argv)
{
	int	i;

	if (philo && philo->init)
	{
		philo->init->number_of_philo = ft_atol(argv[1]);
		philo->init->time_to_die = ft_atol(argv[2]);
		philo->init->time_to_eat = ft_atol(argv[3]);
		philo->init->time_to_sleep = ft_atol(argv[4]);
		if (argv[5])
			philo->init->minimum_eat_times = ft_atol(argv[5]);
		else
			philo->init->minimum_eat_times = 0;
		philo->init->start_time = get_current_time_ms();
		i = 0;
		while (i < philo->init->number_of_philo)
		{
			philo[i].id = i; /* why does this lines crashes the stuff? */
			i++;
		}
	}
}

void	get_philo_values(t_philos *philo, char **argv)
{
	if (philo && philo->init)
	{
		get_time_values(philo, argv);
		printf("Number of philo = %d\n", (int)philo->init->number_of_philo);
		printf("Time to die = %d\n", (int)philo->init->time_to_die);
		printf("Time to eat = %d\n", (int)philo->init->time_to_eat);
		printf("Time to sleep = %d\n", (int)philo->init->time_to_sleep);
		printf("Minimum times to eat= %d\n", (int)philo->init->minimum_eat_times);
	}
}
int check_death(t_philos *philo)
{
	printf("CHECKING DEATH\n");
	// if (philo->times_eaten == philo->init->minimum_eat_times)
	// 	return (-1);
	printf("BRUH\n");
	if (get_current_time_ms() - philo->init->time_of_last_meal > philo->init->time_to_eat)
		return (printf("some dude died\n"), philo->death_flag = 1, -1);
	return (0);
}

void	print_message(t_philos *philo, char *str)
{
	t_time	now;
	t_time	start;
	start = philos()->init->start_time;
	philo = philos();
	now = get_current_time_ms() - start;
	printf("Time of day: %u | Philo id: %d %s", (unsigned int)now, philo->id,
		str);
}

int	create_threads(int number_of_philos, pthread_t th[number_of_philos],
		t_philos *philo)
{
	int	i;

	i = 0;
	(void)philo;
	for (i = 0; i < number_of_philos; i++)
	{
		if (pthread_create(&th[i], NULL, &socrates, NULL) != 0)
			return (perror("Fracassado\n"), 1);
		// philo[i].id = i;
	}
	printf("Finished giving birth to %d philosophers\n", i);
	return (0);
}

int master_loop(t_philos *philo)
{
	printf("INSIDE MASTER LOOP\n");
	// while (philo->death_flag == 0)
	// {
		if (philo_thinking(&philo[5]) != 0)
			return (-1);
		if (philo_sleeping(&philo[5]) != 0)
			return (-1);
		if (philo_eating(&philo[5]) != 0)
			return (-1);
	// }
	return (0);
}

int	join_threads(int number_of_philos, pthread_t th[number_of_philos])
{
	int i;

	i = 0;
	for (i = 0; i < number_of_philos; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (printf("Couldn't join the threads\n"), 1);
	}
	printf("Finished joining threads\n");
	return (0);
}