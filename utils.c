/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:43:53 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/24 23:15:33 by vvazzs           ###   ########.fr       */
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
	while (str[i])
	{
		if (str[0] == '+')
			i++;
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
	return (t_time)(tv.tv_sec * 1000ULL + tv.tv_usec / 1000ULL);
	/*  milliseconds */
	/* 	1000ULL -> converts to miliss
	tv.tv_usec / 1000ULL -> convert microseconds to miliseconds
	time_t tv_sec;   // seconds since Jan 1, 1970 (the Unix epoch)
	suseconds_t tv_usec; // microseconds (millionths of a second) */
}
size_t ft_strlen(char *str)
{
	size_t i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
		// search about this right here
}

void ft_usleep(size_t milliseconds)
{
    usleep(milliseconds * 1000);
}
