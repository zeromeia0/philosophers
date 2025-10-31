/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:43:53 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/31 16:53:29 by vvazzs           ###   ########.fr       */
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

void	ft_usleep(size_t milliseconds, t_philos *philo)
{
	t_time	start;

	start = get_current_time_ms();
	while ((get_current_time_ms() - start) < milliseconds)
	{
		if (should_stop(philo))
			break ;
		usleep(500);
	}
}
