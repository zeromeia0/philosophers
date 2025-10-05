/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:22:19 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/05 22:58:43 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PHILO_H
# define PHILO_H

# include <dirent.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/stat.h>
# include <termios.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
#include <threads.h>
# include <pthread.h>
#include <sys/time.h>

# define SLEEP "%d %d is sleeping"

typedef struct s_init_vars{
    int number_of_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int minimum_eat_times;
}   t_init;

typedef struct s_philo{
    int death_flag;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    int             times_eaten;
    t_init *init;
}   t_philos;

long	ft_atol(const char *str);
int ft_strlen(char *str);
void    ft_putstr_fd(int fd, char *str);
int is_number(char *str);
void	get_values(t_init *init, char **argv);
int	create_threads(int number_of_philos, pthread_t th[number_of_philos]);
int	join_threads(int number_of_philos, pthread_t th[number_of_philos]);
void	*socrates(void *arg);


#endif