/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:58:38 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/10/13 23:30:49 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine_loop(void *arg)
{
	t_philos *philo;
	philo = (t_philos *)arg;
	if (philo->id % 2 == 0)
		usleep(10);
	for (int i = 0; i < 5; i++)
	{
		if (philo_eating(philo) != 0)
			break ;
		if (philo_sleeping(philo) != 0)
			break ;
		if (philo_thinking(philo) != 0)
			break ;
	}
	return (NULL);
}

int	philo_sleeping(t_philos *philo)
{
	if (check_death(philo) != 0)
		return (-1);
	// if (!(philo->left_fork = malloc(sizeof(pthread_mutex_t))))
	// 	return (printf("FAILURE\n"), -1);
	// if (!(philo->right_fork = malloc(sizeof(pthread_mutex_t))))
	// 	return (printf("FAILURE 2\n"), -1);
	// pthread_mutex_unlock(philo->left_fork);
	// pthread_mutex_unlock(philo->right_fork);
	print_message(philo, CLR_BLUE "Is sleeping\n" CLR_RESET);
	usleep((int)philo->init->time_to_sleep);
	return (0);
}

int	philo_thinking(t_philos *philo)
{
	if (check_death(philo) != 0)
		return (-1);
	// if (!(philo->left_fork = malloc(sizeof(pthread_mutex_t))))
	// 	return (printf("FAILURE\n"), -1);
	// if (!(philo->right_fork = malloc(sizeof(pthread_mutex_t))))
	// 	return (printf("FAILURE 2\n"), -1);
	// pthread_mutex_unlock(philo->left_fork);
	// pthread_mutex_unlock(philo->right_fork);
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
	philo->init->food_counter++;
	philo->init->time_of_last_meal = (int)get_current_time() - philo->init->start_time;
	pthread_mutex_unlock(philo->left_fork);
	print_message(philo, "Dropped left fork\n");
	pthread_mutex_unlock(philo->right_fork);
	print_message(philo, "Dropped right fork\n");
	usleep((int)philo->init->time_to_eat);
	return (0);
}