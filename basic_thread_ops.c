/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_thread_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:12:28 by vvazzs            #+#    #+#             */
/*   Updated: 2025/11/07 22:09:33 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philos *philo)
{
	unsigned int	now;

	pthread_mutex_lock(&philo->init->death_lock);
	now = get_current_time_ms() - philo->init->start_time;
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
		printf("%u %d %s", (unsigned int)now, philo->id + 1, str);
	if (is_dead == 1)
		printf("%u %d %s", (unsigned int)now, philo->id + 1, str);
	pthread_mutex_unlock(&philo->init->print_lock);
}

int	create_threads(int number_of_philos, pthread_t th[number_of_philos],
		t_philos *philo)
{
	int	i;

	i = 0;
	(void)philo;
	while (i < number_of_philos)
	{
		if (pthread_create(&th[i], NULL, &routine_loop, &philo[i]) != 0)
			return (perror("Couldn't create threads\n"), 1);
		i++;
	}
	return (0);
}

int	join_threads(int number_of_philos, pthread_t th[number_of_philos])
{
	int	i;

	i = 0;
	while (i < number_of_philos)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (printf("Couldn't join the threads\n"), 1);
		i++;
	}
	return (0);
}

void	super_duper_hiper_free(t_philos *philo, t_init *init, pthread_t *thread)
{
	pthread_mutex_destroy(&philo->init->absolute_lock);
	pthread_mutex_destroy(&philo->lock_to_message);
	free(init->general_forks);
	if (init)
		free(init);
	if (philo)
		free(philo);
	if (thread)
		free(thread);
}
