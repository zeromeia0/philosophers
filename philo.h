/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:41:56 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/05 18:13:28 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <dirent.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/stat.h>
# include <termios.h>
# include <sys/wait.h>
# include <signal.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_init_vars{
    int number_of_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int minimum_eat_times;
}   t_init;

typedef struct s_philo{
    t_init *init;
}   t_philo;

int	ft_atoi(char *str);

