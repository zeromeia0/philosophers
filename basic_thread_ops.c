/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_thread_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:12:28 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/30 10:55:39 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* void	print_message(t_philos *philo, char *str, int is_dead)
{
	t_time	now;
	t_time	start;
	start = philo->init->start_time;
	now = get_current_time_ms() - start;
	pthread_mutex_lock(&philo->lock_to_message);
	if (should_stop(philo) == 0 && is_dead == 0)
		printf("Time of day: %u | Philo id: %d %s", (U_INT)now, philo->id + 1,
		str);
	if (is_dead == 1)
	{
		printf("Time of day: %u | Philo id: %d %s", (U_INT)now, philo->id + 1,
		str);
	}
	pthread_mutex_unlock(&philo->lock_to_message);
} */

int check_death(t_philos *philo)
{
	if ((U_INT)get_current_time_ms() - (U_INT)philo->time_of_last_meal - (U_INT)philo->init->start_time > (U_INT)philo->init->time_to_die)
		return (philo->pass_away_flag = 1, -1);
	return (0);
}

void	print_message(t_philos *philo, char *str, int is_dead)
{
	t_time	now;
	t_time	start;
	start = philo->init->start_time;
	now = get_current_time_ms() - start;
	pthread_mutex_lock(&philo->lock_to_message);
	if (should_stop(philo) == 0 && is_dead == 0)
		printf("%u %d %s", (U_INT)now, philo->id + 1, str);
	if (is_dead == 1)
		printf("%u %d %s", (U_INT)now, philo->id + 1, str);
	pthread_mutex_unlock(&philo->lock_to_message);
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
			return (perror("Fracassado\n"), 1);
	}
	// printf("Finished giving birth to %d philosophers\n", i);
	return (0);
}

int	join_threads(int number_of_philos, pthread_t th[number_of_philos])
{
	int i;

	// i = 0;
	printf("join threads\n");
	for (i = 0; i < number_of_philos; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (printf("Couldn't join the threads\n"), 1);
		printf("joined\n");
	}
	printf("Finished joining threads\n");
	return (0);
}