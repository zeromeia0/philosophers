/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:52:09 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/11/07 22:08:47 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lonely_philo(t_philos *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, CLR_GREEN "has taken a fork\n" CLR_RESET, 0);
	pthread_mutex_unlock(philo->left_fork);
	ft_usleep(philo->init->time_to_die, philo);
}

void	additional_operations(t_philos *philo)
{
	pthread_mutex_lock(&philo->init->food_lock);
	if (philo->init->minimum_eat_times
		* philo->init->number_of_philo > philo->init->food_counter)
		philo->init->food_counter++;
	pthread_mutex_unlock(&philo->init->food_lock);
	pthread_mutex_lock(&philo->init->death_lock);
	philo->time_of_last_meal = get_current_time_ms() - philo->init->start_time;
	pthread_mutex_unlock(&philo->init->death_lock);
}

void	release_forks(t_philos *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

int	delivery_calculator(t_philos *philo)
{
	pthread_mutex_lock(&philo->init->food_lock);
	if (philo->init->food_counter == philo->init->minimum_eat_times
		* philo->init->number_of_philo)
	{
		pthread_mutex_unlock(&philo->init->food_lock);
		return (philo->init->stop_simulation = 1, -1);
	}
	pthread_mutex_unlock(&philo->init->food_lock);
	return (0);
}

void	monitor_helper(t_philos *philo)
{
	pthread_mutex_lock(&philo->init->absolute_lock);
	pthread_mutex_lock(&philo->init->stop_lock);
	philo->init->stop_simulation = 1;
	pthread_mutex_unlock(&philo->init->stop_lock);
	pthread_mutex_unlock(&philo->init->absolute_lock);
}
