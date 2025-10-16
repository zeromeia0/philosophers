/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 23:07:19 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/16 20:59:19 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <bits/pthreadtypes.h>

void	init_values(t_philos *philo, char **argv)
{
	int	i;

	if (!philo || !philo->init)
		return;
	philo->init->number_of_philo = ft_atol(argv[1]);
	philo->init->time_to_die = ft_atol(argv[2]);
	philo->init->time_to_eat = ft_atol(argv[3]);
	philo->init->time_to_sleep = ft_atol(argv[4]);
	philo->init->minimum_eat_times = argv[5] ? ft_atol(argv[5]) : -1;
	philo->init->start_time = get_current_time_ms();
	philo->init->food_counter = 0;
	philo->init->general_forks = malloc(sizeof(pthread_mutex_t) * philo->init->number_of_philo);
	if (!philo->init->general_forks)
		return;
	i = -1;
	while (++i < philo->init->number_of_philo)
		pthread_mutex_init(&philo->init->general_forks[i], NULL);
	i = -1;
	while (++i < philo->init->number_of_philo)
	{
		philo[i].id = i;
		philo[i].init = philo->init;
		philo[i].left_fork = &philo->init->general_forks[i];
		philo[i].right_fork = &philo->init->general_forks[(i + 1) % philo->init->number_of_philo];
	}
}


void	print_philo_values(t_philos *philo, char **argv)
{
	if (philo && philo->init)
	{
		init_values(philo, argv);
		printf("Number of philo = %d\n", (int)philo->init->number_of_philo);
		printf("Time to die = %d\n", (int)philo->init->time_to_die);
		printf("Time to eat = %d\n", (int)philo->init->time_to_eat);
		printf("Time to sleep = %d\n", (int)philo->init->time_to_sleep);
		printf("Minimum times to eat= %d\n", (int)philo->init->minimum_eat_times);
	}
}

void crazy_print(t_philos *philo)
{
	t_time current_time_ms = get_current_time_ms();
	t_time start_time = philo->init->start_time;
	t_time last_meal = philo->time_of_last_meal;
	t_time time_to_die = philo->init->time_to_die;

	unsigned int elapsed_time = (unsigned int)(get_current_time() - start_time);
	unsigned int time_since_meal = (unsigned int)(current_time_ms - last_meal - start_time);

	printf("========================\n");
	printf("Current time      = %u\n", elapsed_time);
	printf("Time of last meal = %u\n", (unsigned int)last_meal);
	printf("Time to die       = %u\n", (unsigned int)time_to_die);
	printf("========================\n");

	printf("Final result      = %u > %u\n", 
		(unsigned int)time_since_meal, 
		(unsigned int)time_to_die);
	printf("========================\n");
}