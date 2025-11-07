/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_thread_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:12:28 by vvazzs            #+#    #+#             */
/*   Updated: 2025/11/07 14:20:27 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_death(t_philos *philo)
{
	pthread_mutex_lock(&philo->init->death_lock);
	U_INT now = get_current_time_ms() - philo->init->start_time;
	if (now - philo->time_of_last_meal > philo->init->time_to_die)
	{
		philo->pass_away_flag = 1;
		pthread_mutex_unlock(&philo->init->death_lock);
		return (-1);
	}
	pthread_mutex_unlock(&philo->init->death_lock);
	return (0);
}

void	print_message(t_philos *philo, char *str, int is_dead)
{
	t_time	now;
	t_time	start;
	start = philo->init->start_time;
	pthread_mutex_lock(&philo->init->print_lock);
	now = get_current_time_ms() - start;
	if (should_stop(philo) == 0 && is_dead == 0)
		printf("%u %d %s", (U_INT)now, philo->id + 1, str);
	if (is_dead == 1)
		printf("%u %d %s", (U_INT)now, philo->id + 1, str);
	pthread_mutex_unlock(&philo->init->print_lock);
}

int	create_threads(int number_of_philos, pthread_t th[number_of_philos],
		t_philos *philo)
{
	int	i;

	i = 0;
	(void)philo;
	for (i = 0; i < number_of_philos; i++)
	{
		if (pthread_create(&th[i], NULL, &routine_loop, &philo[i]) != 0)
			return (perror("Couldn't create threads\n"), 1);
	}
	return (0);
}

int	join_threads(int number_of_philos, pthread_t th[number_of_philos])
{
	int i;

	// i = 0;
	for (i = 0; i < number_of_philos; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (printf("Couldn't join the threads\n"), 1);
	}
	return (0);
}
