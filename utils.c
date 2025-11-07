/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:43:53 by vvazzs            #+#    #+#             */
/*   Updated: 2025/11/07 21:36:30 by vivaz-ca         ###   ########.fr       */
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

void ft_usleep(t_time milliseconds, t_philos *philo)
{
    t_time start = get_current_time_ms();
    while (get_current_time_ms() - start < milliseconds)
    {
        if (should_stop(philo))
            break;
        usleep(500);
    }
}

// 5 600 200 200
// ====exiting====
// ==================
// WARNING: ThreadSanitizer: data race (pid=131091)
//   Write of size 8 at 0x7b5c00000208 by thread T4 (mutexes: write M9, write M10, write M2):
//     #0 philo_eating /home/vivaz-ca/42_Cursus/philosophers/philo_actions.c:113:27 (philo+0x4bb284)
//     #1 routine_loop /home/vivaz-ca/42_Cursus/philosophers/philo_actions.c:35:7 (philo+0x4bad3c)

//   Previous read of size 8 at 0x7b5c00000208 by main thread:
//     #0 monitor /home/vivaz-ca/42_Cursus/philosophers/philo.c:89:56 (philo+0x4ba1b3)
//     #1 main /home/vivaz-ca/42_Cursus/philosophers/philo.c:149:2 (philo+0x4ba81f)

//   Location is heap block of size 840 at 0x7b5c00000000 allocated by main thread:
//     #0 calloc <null> (philo+0x448677)
//     #1 main /home/vivaz-ca/42_Cursus/philosophers/philo.c:135:16 (philo+0x4ba5db)

//   Mutex M9 (0x7b3400000078) created at:
//     #0 pthread_mutex_init <null> (philo+0x44b47d)
//     #1 init_values /home/vivaz-ca/42_Cursus/philosophers/init.c:51:3 (philo+0x4bb882)
//     #2 __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16 (libc.so.6+0x29d8f)

//   Mutex M10 (0x7b34000000a0) created at:
//     #0 pthread_mutex_init <null> (philo+0x44b47d)
//     #1 init_values /home/vivaz-ca/42_Cursus/philosophers/init.c:51:3 (philo+0x4bb882)
//     #2 __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16 (libc.so.6+0x29d8f)

//   Mutex M2 (0x7b4000000058) created at:
//     #0 pthread_mutex_init <null> (philo+0x44b47d)
//     #1 init_heleper /home/vivaz-ca/42_Cursus/philosophers/init.c:32:2 (philo+0x4bb76d)
//     #2 __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16 (libc.so.6+0x29d8f)

//   Thread T4 (tid=131096, running) created by main thread at:
//     #0 pthread_create <null> (philo+0x449c4b)
//     #1 create_threads /home/vivaz-ca/42_Cursus/philosophers/basic_thread_ops.c:52:7 (philo+0x4bab00)
//     #2 __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16 (libc.so.6+0x29d8f)

// SUMMARY: ThreadSanitizer: data race /home/vivaz-ca/42_Cursus/philosophers/philo_actions.c:113:27 in philo_eating
// ==================
