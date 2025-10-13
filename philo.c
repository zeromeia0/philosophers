/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:43:22 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/13 17:04:50 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdbool.h>

int	args_checker(int argc, char *argv[]) // NEED TO TEST BIG ASS NUMBERS?
{
	int i = 1;
	while (i < argc)
	{
		if (is_number(argv[i]) != 0)
			return (write(2, "Arguments should be numbers only\n", 34), 1);
		i++;
	}
	if (argc < 5 || argc > 6)
		return (printf("Invalid number of args\n"), 1);
	return (0);
}

// check death
int	main(int argc, char *argv[])
{
	int			number_of_philo;
	pthread_t	*threads;
	t_init		*init;
	t_philos	*philo;

	if (args_checker(argc, argv) != 0)
		return (1);
		
	number_of_philo = ft_atol(argv[1]);
	if (!(init = malloc(sizeof(t_init))))
		return (printf("Couldn't load init\n"), -1);
	if (!(philo = malloc(sizeof(t_philos) * number_of_philo)))
		return (printf("Couldn't load main struct\n"), -1);
	if (!(threads = malloc(sizeof(pthread_t) * number_of_philo)))
		return (printf("Couldn't allocate threads\n"), -1);

	for (int i = 0; i < number_of_philo; i++)
	{
		philo[i].id = i;
		printf("ID CREATION: %d\n", philo[i].id);
		philo[i].init = init;
	}
	print_philo_values(philo, argv);
	
	if (create_threads(number_of_philo, threads, philo) != 0)
		return (perror("Not working right now\n"), 1);
	// master_loop(&philo[1]);
	if (join_threads(number_of_philo, threads) != 0)
		return (perror("Failure\n"), 1);
	// printf("FINISHED ACIONS\n");
	printf("Number of philos: %s\n", argv[1]);
	if (init)
		free(init);
	// if (philo)
		// free(philo);
	// free(main_philo->left_fork);
	// free(main_philo->right_fork);
	return (0);
}
