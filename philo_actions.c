/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:58:38 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/11/07 21:53:27 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	should_stop(t_philos *philo)
{
	int	stop;

	pthread_mutex_lock(&philo->init->stop_lock);
	stop = philo->init->stop_simulation;
	pthread_mutex_unlock(&philo->init->stop_lock);
	return (stop);
}

void	*routine_loop(void *arg)
{
	t_philos	*philo;
	bool		should_do;

	should_do = true;
	philo = (t_philos *)arg;
	while (!should_stop(philo))
	{
		if (philo->id % 2 == 1 && should_do)
		{
			ft_usleep(philo->init->time_to_eat / 2, philo);
			should_do = false;
		}
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
	pthread_mutex_lock(&philo->init->absolute_lock);
	if (check_death(philo) != 0)
		return (pthread_mutex_unlock(&philo->init->absolute_lock), -1);
	print_message(philo, CLR_BLUE "is sleeping\n" CLR_RESET, 0);
	pthread_mutex_unlock(&philo->init->absolute_lock);
	ft_usleep((size_t)philo->init->time_to_sleep, philo);
	return (0);
}

int	philo_thinking(t_philos *philo)
{
	pthread_mutex_lock(&philo->init->absolute_lock);
	if (check_death(philo) != 0)
		return (pthread_mutex_unlock(&philo->init->absolute_lock), -1);
	print_message(philo, CLR_MAGENTA "is thinking\n" CLR_RESET, 0);
	pthread_mutex_unlock(&philo->init->absolute_lock);
	return (0);
}

int	philo_eating(t_philos *philo)
{
	if (check_death(philo) != 0)
		return (-1);
	if (philo->init->number_of_philo == 1)
		return (lonely_philo(philo), 1);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, CLR_GREEN "has taken a right fork\n" CLR_RESET, 0);
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, CLR_GREEN "has taken left a fork\n" CLR_RESET, 0);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, CLR_GREEN "has taken left a fork\n" CLR_RESET, 0);
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, CLR_GREEN "has taken a right fork\n" CLR_RESET, 0);
	}
	print_message(philo, CLR_YELLOW "is eating\n" CLR_RESET, 0);
	additional_operations(philo);
	ft_usleep(philo->init->time_to_eat, philo);
	release_forks(philo);
	return (0);
}
