/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:22:19 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/06 22:29:41 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <dirent.h>
# include <pthread.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <termios.h>
# include <threads.h>
# include <unistd.h>

# define SLEEP "%d %d is sleeping"

typedef unsigned long long	t_time;

typedef struct s_init_vars
{
	int						number_of_philo;
	t_time					time_to_die;
	t_time					time_to_eat;
	t_time					time_to_sleep;
	t_time					minimum_eat_times;
	t_time					start_time;
}							t_init;

typedef struct s_philo
{
	int						death_flag;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	int						times_eaten;
	int						id;
	t_init					*init;
}							t_philos;

long						ft_atol(const char *str);
int							ft_strlen(char *str);
void						ft_putstr_fd(int fd, char *str);
int							is_number(char *str);
void	get_time_values(t_philos *philo, char **argv);
int							create_threads(int number_of_philos,
								pthread_t th[number_of_philos],
								t_philos *philo);
int							join_threads(int number_of_philos,
								pthread_t th[number_of_philos]);
void						*socrates(void *arg);
void print_message(t_philos *philo, char *str);
t_philos	*philos(void);
void get_philo_values(t_philos *philo, char **argv);

#endif