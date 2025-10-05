/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:43:22 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/05 19:34:20 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

t_philo	*philos(void)
{
	static t_philo	philosophers;

	return (&philosophers);
}

void	*socrates(void *arg)
{
	(void)arg;
	// printf("A philosopher is being created\n");
	return (NULL);
}

void	get_values(t_init *init, char **argv)
{
	if (init)
	{
		init->number_of_philo = ft_atoi(argv[1]);
		init->time_to_die = ft_atoi(argv[2]);
		init->time_to_eat = ft_atoi(argv[3]);
		init->time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			init->minimum_eat_times = ft_atoi(argv[5]);
		else
			init->minimum_eat_times = 0;
	}
	printf("Number of philo = %d\n", init->number_of_philo);
	printf("Time to die = %d\n", init->time_to_die);
	printf("Time to eat = %d\n", init->time_to_eat);
	printf("Time to sleep = %d\n", init->time_to_sleep);
	printf("Minimum times to eat= %d\n", init->minimum_eat_times);
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

int	main(int argc, char *argv[])
{
	t_philo *main_philo = philos();
	int number_of_philo = ft_atoi(argv[1]);

	pthread_t threads[number_of_philo];
	if (argc < 5 || argc > 6)
		return (printf("Invalid number of args\n"), 0);
	main_philo->init = malloc(sizeof(t_init));
	if (!main_philo->init)
		return (printf("can't alloc memory for that\n"), 0);

	get_values(philos()->init, argv);

	if (create_threads(number_of_philo, threads) != 0)
		return (perror("Not working right now\n"), 1);
	if (join_threads(number_of_philo, threads) != 0)
		return (perror("Failure\n"), 1);

	printf("Number of philos: %s", argv[1]);
	free(main_philo->init);
	return (0);
}