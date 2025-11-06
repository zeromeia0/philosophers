/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 23:07:19 by vvazzs            #+#    #+#             */
/*   Updated: 2025/11/06 14:23:17 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>

void	init_heleper(t_philos *philo, char **argv)
{
	philo->init->number_of_philo = ft_atol(argv[1]);
	philo->init->time_to_die = ft_atol(argv[2]);
	philo->init->time_to_eat = ft_atol(argv[3]);
	philo->init->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		philo->init->minimum_eat_times = ft_atol(argv[5]);
	else
		philo->init->minimum_eat_times = -1;
	philo->init->start_time = get_current_time_ms();
	philo->init->food_counter = 0;
	philo->init->stop_simulation = 0;
	pthread_mutex_init(&philo->init->stop_lock, NULL);
	pthread_mutex_init(&philo->init->absolute_lock, NULL);
	pthread_mutex_init(&philo->init->death_lock, NULL);
	pthread_mutex_init(&philo->init->food_lock, NULL);
}

void	init_values(t_philos *philo, char **argv)
{
	int	i;

	if (!philo || !philo->init)
		return ;
	init_heleper(philo, argv);
	philo->init->general_forks = malloc(sizeof(pthread_mutex_t)
			* philo->init->number_of_philo);
	pthread_mutex_init(&philo->lock_to_message, NULL);
	if (!philo->init->general_forks)
		return ;
	i = -1;
	while (++i < philo->init->number_of_philo)
		pthread_mutex_init(&philo->init->general_forks[i], NULL);
	i = -1;
	while (++i < philo->init->number_of_philo)
	{
		philo[i].id = i;
		philo[i].init = philo->init;
		philo[i].left_fork = &philo->init->general_forks[i];
		philo[i].right_fork = &philo->init->general_forks[(i + 1)
			% philo->init->number_of_philo];
	}
}

void	print_philo_values(t_philos *philo, char **argv)
{
	if (philo && philo->init)
	{
		printf("Number of philo = %d\n", (int)philo->init->number_of_philo);
		printf("Time to die = %d\n", (int)philo->init->time_to_die);
		printf("Time to eat = %d\n", (int)philo->init->time_to_eat);
		printf("Time to sleep = %d\n", (int)philo->init->time_to_sleep);
		printf("Minimum times to eat= %d\n",
			(int)philo->init->minimum_eat_times);
	}
}
/* 
void	crazy_print(t_philos *philo)
{
	t_time	current_time_ms;
	t_time	start_time;
	t_time	last_meal;
	t_time	time_to_die;
	U_INT	elapsed_time;
	U_INT	time_since_meal;

	current_time_ms = get_current_time_ms();
	start_time = philo->init->start_time;
	last_meal = philo->time_of_last_meal;
	time_to_die = philo->init->time_to_die;
	elapsed_time = (U_INT)(get_current_time_ms() - start_time);
	time_since_meal = (U_INT)(current_time_ms - last_meal - start_time);
	printf("========================\n");
	printf("Current time      = %u\n", elapsed_time);
	printf("Time of last meal = %u\n", (U_INT)last_meal);
	printf("Time to die       = %u\n", (U_INT)time_to_die);
	printf("========================\n");
	printf("Final result      = %u > %u\n", (U_INT)time_since_meal,
		(U_INT)time_to_die);
	printf("========================\n");
}
 */