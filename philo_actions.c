/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:58:38 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/10/30 14:16:55 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int should_stop(t_philos *philo)
{
    pthread_mutex_lock(&philo->init->stop_lock);
    int stop = philo->init->stop_simulation;
    pthread_mutex_unlock(&philo->init->stop_lock);
    return stop;
}

void *routine_loop(void *arg)
{
	t_philos *philo;
	philo = (t_philos *)arg;
	while (!should_stop(philo))
	{
	if (philo->id % 2 == 1)
		ft_usleep(philo->init->time_to_eat / 2, philo);
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
	print_message(philo, CLR_BLUE "is sleeping\n" CLR_RESET, 0);
	ft_usleep((size_t)philo->init->time_to_sleep, philo);
	return (0);
}

int	philo_thinking(t_philos *philo)
{
	if (check_death(philo) != 0)
		return (-1);
	print_message(philo, CLR_MAGENTA "is thinking\n" CLR_RESET, 0);
	if ((int)philo->init->time_to_eat >= (int)philo->init->time_to_sleep)
		ft_usleep((int)philo->init->time_to_eat -  (int)philo->init->time_to_sleep, philo);
	else
	 	ft_usleep((int)philo->init->time_to_sleep - (int)philo->init->time_to_eat, philo);
	return (0);
}

int	philo_eating(t_philos *philo)
{
	if (check_death(philo) != 0)
		return (-1);
	if (philo->init->number_of_philo == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, CLR_GREEN"has taken a fork\n" CLR_RESET, 0);
		pthread_mutex_unlock(philo->left_fork);
		ft_usleep(philo->init->time_to_die, philo);
		return (1);
	}
	// pthread_mutex_lock(philo->init->general_forks);
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, CLR_GREEN"has taken left a fork\n" CLR_RESET, 0);
	pthread_mutex_lock(philo->right_fork);
	print_message(philo, CLR_GREEN"has taken a right fork\n" CLR_RESET, 0);
	print_message(philo, CLR_YELLOW "is eating\n" CLR_RESET, 0);
	philo->init->food_counter++;
	// printf("\n====Food counter: %d====\n", philo->init->food_counter);
	philo->time_of_last_meal = (int)get_current_time_ms() - philo->init->start_time;
	ft_usleep(philo->init->time_to_eat, philo);
	pthread_mutex_unlock(philo->right_fork);
	print_message(philo, "Dropped right fork\n", 0);
	pthread_mutex_unlock(philo->left_fork);
	print_message(philo, "Dropped left fork\n", 0);
	// pthread_mutex_unlock(philo->init->general_forks);
	return (0);
}
