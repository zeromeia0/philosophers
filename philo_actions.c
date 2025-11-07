/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:58:38 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/11/07 15:21:19 by vivaz-ca         ###   ########.fr       */
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
	bool should_do = true;
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
	if (philo->id % 2 == 0)
	{
	    pthread_mutex_lock(philo->right_fork);
	    print_message(philo, CLR_GREEN"has taken a right fork\n" CLR_RESET, 0);
	    pthread_mutex_lock(philo->left_fork);
	    print_message(philo, CLR_GREEN"has taken left a fork\n" CLR_RESET, 0);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, CLR_GREEN"has taken left a fork\n" CLR_RESET, 0);
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, CLR_GREEN"has taken a right fork\n" CLR_RESET, 0);
	}
	print_message(philo, CLR_YELLOW "is eating\n" CLR_RESET, 0);
	pthread_mutex_lock(&philo->init->food_lock);
	philo->init->food_counter++;
	pthread_mutex_unlock(&philo->init->food_lock);
	pthread_mutex_lock(&philo->init->death_lock);
	philo->time_of_last_meal = get_current_time_ms() - philo->init->start_time;
	pthread_mutex_unlock(&philo->init->death_lock);
	ft_usleep(philo->init->time_to_eat, philo); //THE PROBLEM IS HERE
	release_forks(philo);
	return (0);
}
