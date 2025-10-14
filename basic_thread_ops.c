/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_thread_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:12:28 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/14 15:41:31 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_death(t_philos *philo)
{
	// if (philo->init->minimum_eat_times != -1 && philo->init->food_counter == philo->init->minimum_eat_times * philo->init->number_of_philo)
	// 	return (printf("BARRIGA CHEIA\n"), -1);
	crazy_print(philo);
	if ((unsigned int)get_current_time_ms() - (unsigned int)philo->init->time_of_last_meal - (unsigned int)philo->init->start_time >= (unsigned int)philo->init->time_to_die)
		return (printf("died of hunger\n"), -1);
	return (0);
}

void	print_message(t_philos *philo, char *str)
{
	t_time	now;
	t_time	start;
	start = philo->init->start_time;
	now = get_current_time_ms() - start;
	printf("Time of day: %u | Philo id: %d %s", (unsigned int)now, philo->id + 1,
		str);
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
	printf("Finished giving birth to %d philosophers\n", i);
	return (0);
}


int	join_threads(int number_of_philos, pthread_t th[number_of_philos])
{
	int i;

	i = 0;
	for (i = 0; i < number_of_philos; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (printf("Couldn't join the threads\n"), 1);
	}
	printf("Finished joining threads\n");
	return (0);
}