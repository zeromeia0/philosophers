/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 23:07:19 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/13 23:08:12 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_values(t_philos *philo, char **argv)
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
			philo->init->minimum_eat_times = -1;
		philo->init->start_time = get_current_time_ms();
		philo->init->food_counter = 0;
		i = 0;
		while (i < philo->init->number_of_philo)
		{
			philo[i].id = i;
			i++;
		}
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