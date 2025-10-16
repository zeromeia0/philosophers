/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:58:38 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/10/16 21:21:20 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine_loop(void *arg)
{
	t_philos *philo;
	philo = (t_philos *)arg;
	while (check_death(philo) != -1 && delivery_calculator(philo) != 1)
	{
	if (philo->id % 2 == 1)
		ft_usleep(100);
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
	print_message(philo, CLR_BLUE "Is sleeping\n" CLR_RESET);
	ft_usleep((int)philo->init->time_to_sleep);
	return (0);
}

int	philo_thinking(t_philos *philo)
{
	if (check_death(philo) != 0)
		return (-1);
	int total = (int)philo->init->time_to_die - (int)philo->init->time_to_eat - (int)philo->init->time_to_sleep;
	if (total < 0)
		total = 0;
	ft_usleep(total);
	print_message(philo, CLR_MAGENTA "Is thinking\n" CLR_RESET);
	return (0);
}

int	philo_eating(t_philos *philo)
{
	if (check_death(philo) != 0)
		return (-1);
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, CLR_GREEN"Grabbed left fork\n" CLR_RESET);
	pthread_mutex_lock(philo->right_fork);
	print_message(philo, CLR_GREEN"Grabbed right fork\n" CLR_RESET);
	print_message(philo, CLR_YELLOW "Is eating\n" CLR_RESET);
	philo->init->food_counter++;
	philo->time_of_last_meal = (int)get_current_time() - philo->init->start_time;
	pthread_mutex_unlock(philo->left_fork);
	print_message(philo, "Dropped left fork\n");
	pthread_mutex_unlock(philo->right_fork);
	print_message(philo, "Dropped right fork\n");
	ft_usleep((int)philo->init->time_to_eat);
	return (0);
}