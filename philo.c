/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:43:22 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/06 23:09:01 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdbool.h>

t_philos	*philos(void)
{
	static t_philos	philosophers;

	return (&philosophers);
}

void	*socrates(void *arg)
{
	(void)arg;
	// printf("A philosopher is being created\n");
	return (NULL);
}

int args_checker(int argc, char *argv[]) //NEED TO TEST BIG ASS NUMBERS?
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

int philo_sleeping(t_philos *philo)
{
	printf("PHILO IS SLEEPING\n");
	if (!(philo->left_fork = malloc(sizeof(pthread_mutex_t))))
		return (printf("FAILURE\n"), -1);
	if (!(philo->right_fork = malloc(sizeof(pthread_mutex_t))))
		return (printf("FAILURE 2\n"), -1);
    pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (philos()->death_flag != 0)
		return (-1);
	print_message(philo, "Is sleeping\n");
	return (0);
}

int philo_thinking(t_philos *philo)
{
	printf("PHILO IS THINKING\n");
	if (!(philo->left_fork = malloc(sizeof(pthread_mutex_t))))
		return (printf("FAILURE\n"), -1);
	if (!(philo->right_fork = malloc(sizeof(pthread_mutex_t))))
		return (printf("FAILURE 2\n"), -1);
	
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_message(philo, "Is thinking\n");
	return (0);
}

int philo_eating(t_philos *philo)
{
	printf("PHILO IS EATING\n");
	if (!(philo->left_fork = malloc(sizeof(pthread_mutex_t))))
		return (printf("FAILURE\n"), -1);
	if (!(philo->right_fork = malloc(sizeof(pthread_mutex_t))))
		return (printf("FAILURE 2\n"), -1);
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, "Grabbed left fork\n");
	pthread_mutex_lock(philo->right_fork);
	print_message(philo, "Grabbed right fork\n");
	print_message(philo, "Is eating\n");
	pthread_mutex_unlock(philo->left_fork);
	print_message(philo, "Dropped left fork\n");
	pthread_mutex_unlock(philo->right_fork);
	print_message(philo, "Dropped right fork\n");
	return (0);
}

//check death
int	main(int argc, char *argv[])
{
	t_philos *main_philo = philos();
	int number_of_philo = ft_atol(argv[1]);
	// pthread_mutex_t *forks;
	pthread_t threads[number_of_philo];
	
	
    if (args_checker(argc, argv) != 0){
		return (1);}
	main_philo->init = malloc(sizeof(t_init));
	if (!main_philo->init)
			return (printf("can't alloc memory for that\n"), 0);
		get_philo_values(philos(), argv);
		
	if (create_threads(number_of_philo, threads, philos()) != 0)
		return (perror("Not working right now\n"), 1);
	printf("BRUH\n");
	
	if (philo_thinking(philos()) != 0)
		return (-1);
	if (philo_sleeping(philos()) != 0)
		return (-1);
	if (philo_eating(philos()) != 0)
		return (-1);
	printf("FINISHED ACIONS\n");
	if (join_threads(number_of_philo, threads) != 0)
		return (perror("Failure\n"), 1);
	// printf("Number of philos: %s\n", argv[1]);

	
	free(main_philo->init);
	// free(main_philo->left_fork);
	// free(main_philo->right_fork);
	return (0);
}
