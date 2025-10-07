/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:43:22 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/07 16:43:41 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdbool.h>

void	*socrates(void *arg)
{
	(void)arg;
	// printf("A philosopher is being created\n");
	return (NULL);
}

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

int	philo_sleeping(t_philos *philo)
{
	if (check_death(philo) != 0)
		return (-1);
	if (!(philo->left_fork = malloc(sizeof(pthread_mutex_t))))
		return (printf("FAILURE\n"), -1);
	if (!(philo->right_fork = malloc(sizeof(pthread_mutex_t))))
		return (printf("FAILURE 2\n"), -1);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (philo->death_flag != 0)
		return (-1);
	print_message(philo, CLR_BLUE "Is sleeping\n" CLR_RESET);
	usleep((int)philo->init->time_to_sleep);
	return (0);
}

int	philo_thinking(t_philos *philo)
{
	if (check_death(philo) != 0)
		return (-1);
	if (!(philo->left_fork = malloc(sizeof(pthread_mutex_t))))
		return (printf("FAILURE\n"), -1);
	if (!(philo->right_fork = malloc(sizeof(pthread_mutex_t))))
		return (printf("FAILURE 2\n"), -1);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	int total = (int)philo->init->time_to_die - (int)philo->init->time_to_eat - (int)philo->init->time_to_sleep;
	if (total < 0)
		total = 0;
	usleep(total);
	print_message(philo, CLR_MAGENTA "Is thinking\n" CLR_RESET);
	return (0);
}

int	philo_eating(t_philos *philo)
{
	if (check_death(philo) != 0)
		return (-1);
	if (!(philo->left_fork = malloc(sizeof(pthread_mutex_t))))
		return (printf("FAILURE\n"), -1);
	if (!(philo->right_fork = malloc(sizeof(pthread_mutex_t))))
		return (printf("FAILURE 2\n"), free(philo->right_fork), -1);
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, CLR_GREEN"Grabbed left fork\n" CLR_RESET);
	pthread_mutex_lock(philo->right_fork);
	print_message(philo, CLR_GREEN"Grabbed right fork\n" CLR_RESET);
	print_message(philo, CLR_YELLOW "Is eating\n" CLR_RESET);
	philo->init->time_of_last_meal = (int)get_current_time() - philo->init->start_time;
	pthread_mutex_unlock(philo->left_fork);
	print_message(philo, "Dropped left fork\n");
	pthread_mutex_unlock(philo->right_fork);
	print_message(philo, "Dropped right fork\n");
	usleep((int)philo->init->time_to_eat);
	
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

	// philo = philos();
	for (int i = 0; i < number_of_philo; i++)
	{
		philo[i].id = i;
		printf("ID CREATION: %d\n", philo[i].id);
		philo[i].init = init;
	}
	get_philo_values(philo, argv);
	
	
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
