/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:43:53 by vvazzs            #+#    #+#             */
/*   Updated: 2025/11/07 22:08:23 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

long	ft_atol(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (!str)
		return (0);
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] == '0' && i < ft_strlen((char *)str))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (str[0] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

t_time	get_current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((t_time)(tv.tv_sec * 1000ULL + tv.tv_usec / 1000ULL));
}
/*
milliseconds
1000ULL -> converts to miliss
tv.tv_usec / 1000ULL -> convert microseconds to miliseconds
time_t tv_sec;   // seconds from 01 jan 1970
suseconds_t tv_usec; // microseconds (millionths of a second)
*/

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_usleep(t_time milliseconds, t_philos *philo)
{
	t_time	start;

	start = get_current_time_ms();
	while (get_current_time_ms() - start < milliseconds)
	{
		if (should_stop(philo))
			break ;
		usleep(500);
	}
}

// 5 800 200 200 3
// WARNING: ThreadSanitizer: data race (pid=133492)
//   Write of size 4 at 0x7b400000000c by main thread:
//     #0 delivery_calculator /home/vivaz-ca/42_Cursus/philosophers/philo.c:61:40 (philo+0x4b9f16)
//     #1 monitor /home/vivaz-ca/42_Cursus/philosophers/philo.c:87:7 (philo+0x4ba100)
//     #2 main /home/vivaz-ca/42_Cursus/philosophers/philo.c:145:2 (philo+0x4ba6af)

//   Previous read of size 4 at 0x7b400000000c by thread T4 (mutexes: write M9, write M10, write M0):
//     #0 should_stop /home/vivaz-ca/42_Cursus/philosophers/philo_actions.c:20:22 (philo+0x4bac97)
//     #1 ft_usleep /home/vivaz-ca/42_Cursus/philosophers/utils.c:96:13 (philo+0x4bc32d)
//     #2 philo_eating /home/vivaz-ca/42_Cursus/philosophers/philo_actions.c:125:2 (philo+0x4bafbd)
//     #3 routine_loop /home/vivaz-ca/42_Cursus/philosophers/philo_actions.c:39:7 (philo+0x4bad9c)

//   As if synchronized via sleep:
//     #0 usleep <null> (philo+0x4473b6)
//     #1 monitor /home/vivaz-ca/42_Cursus/philosophers/philo.c:96:3 (philo+0x4ba1e3)
//     #2 main /home/vivaz-ca/42_Cursus/philosophers/philo.c:145:2 (philo+0x4ba6af)

//   Location is heap block of size 256 at 0x7b4000000000 allocated by main thread:
//     #0 malloc <null> (philo+0x44841b)
//     #1 main /home/vivaz-ca/42_Cursus/philosophers/philo.c:128:15 (philo+0x4ba42b)

//   Mutex M9 (0x7b3400000078) created at:
//     #0 pthread_mutex_init <null> (philo+0x44b47d)
//     #1 init_values /home/vivaz-ca/42_Cursus/philosophers/init.c:51:3 (philo+0x4bbb69)
//     #2 main /home/vivaz-ca/42_Cursus/philosophers/philo.c:139:2 (philo+0x4ba559)

//   Mutex M10 (0x7b34000000a0) created at:
//     #0 pthread_mutex_init <null> (philo+0x44b47d)
//     #1 init_values /home/vivaz-ca/42_Cursus/philosophers/init.c:51:3 (philo+0x4bbb69)
//     #2 main /home/vivaz-ca/42_Cursus/philosophers/philo.c:139:2 (philo+0x4ba559)

//   Mutex M0 (0x7b4000000088) created at:
//     #0 pthread_mutex_init <null> (philo+0x44b47d)
//     #1 init_heleper /home/vivaz-ca/42_Cursus/philosophers/init.c:30:2 (philo+0x4bb8d2)
//     #2 init_values /home/vivaz-ca/42_Cursus/philosophers/init.c:43:2 (philo+0x4bba08)
//     #3 main /home/vivaz-ca/42_Cursus/philosophers/philo.c:139:2 (philo+0x4ba559)

//   Thread T4 (tid=133497, running) created by main thread at:
//     #0 pthread_create <null> (philo+0x449c4b)
//     #1 create_threads /home/vivaz-ca/42_Cursus/philosophers/basic_thread_ops.c:55:7 (philo+0x4bab08)
//     #2 main /home/vivaz-ca/42_Cursus/philosophers/philo.c:143:6 (philo+0x4ba682)

// SUMMARY: ThreadSanitizer: data race /home/vivaz-ca/42_Cursus/philosophers/philo.c:61:40 in delivery_calculator