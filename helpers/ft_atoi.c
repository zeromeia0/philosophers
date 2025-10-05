/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:43:53 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/05 18:13:57 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

    if (!str || !*str){
        return (0);}
	i = 0;
	result = 0;
	sign = 1;
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
