/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_thread_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:12:28 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/05 22:35:37 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_values(t_init *init, char **argv)
{
	if (init)
	{
		init->number_of_philo = ft_atol(argv[1]);
		init->time_to_die = ft_atol(argv[2]);
		init->time_to_eat = ft_atol(argv[3]);
		init->time_to_sleep = ft_atol(argv[4]);
		if (argv[5])
			init->minimum_eat_times = ft_atol(argv[5]);
		else
			init->minimum_eat_times = 0;
	}
	// printf("Number of philo = %d\n", init->number_of_philo);
	// printf("Time to die = %d\n", init->time_to_die);
	// printf("Time to eat = %d\n", init->time_to_eat);
	// printf("Time to sleep = %d\n", init->time_to_sleep);
	// printf("Minimum times to eat= %d\n", init->minimum_eat_times);
}
int	create_threads(int number_of_philos, pthread_t th[number_of_philos])
{
	int	i;

	i = 0;
	for (i = 0; i < number_of_philos; i++)
	{
		if (pthread_create(&th[i], NULL, &socrates, NULL) != 0)
			return (perror("Fracassado\n"), 1);
		// printf("Giving birth to philosopher number %d\n", i);
	}
	printf("Finished giving birth to %d philosophers\n", i);
	return (0);
}
int	join_threads(int number_of_philos, pthread_t th[number_of_philos])
{
	int	i;

	i = 0;
	for (i = 0; i < number_of_philos; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (printf("Couldn't join the threads\n"), 1);
	}
	printf("Finished joining threads\n");
	return (0);
}