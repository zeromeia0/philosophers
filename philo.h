/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:22:19 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/13 23:29:26 by vvazzs           ###   ########.fr       */
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
#include <bits/types/struct_timeval.h>
#include <sys/time.h>
#include <time.h>


#define CLR_RESET   "\033[0m"
#define CLR_RED     "\033[31m"
#define CLR_GREEN   "\033[32m"
#define CLR_YELLOW  "\033[33m"
#define CLR_BLUE    "\033[34m"
#define CLR_MAGENTA "\033[35m"

typedef unsigned long long	t_time;

typedef struct s_init_vars
{
	int						number_of_philo;
	t_time					time_to_die;
	t_time					time_to_eat;
	t_time					time_to_sleep;
	t_time					time_of_last_meal;
	int						minimum_eat_times;
	t_time					start_time;
	int						food_counter;
}							t_init;

typedef struct s_philo
{
	pthread_mutex_t			death_flag;
	int						pass_away_flag;
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
void						init_values(t_philos *philo, char **argv);
int							create_threads(int number_of_philos,
								pthread_t th[number_of_philos],
								t_philos *philo);
int							join_threads(int number_of_philos,
								pthread_t th[number_of_philos]);
void						*socrates(void *arg);
void						print_message(t_philos *philo, char *str);
t_philos					*philos(void);
void						print_philo_values(t_philos *philo, char **argv);
int	philo_thinking(t_philos *philo);
int	philo_sleeping(t_philos *philo);
int	philo_eating(t_philos *philo);
int check_death(t_philos *philo);
void *routine_loop(void *arg);
size_t	get_current_time(void);
t_time	get_current_time_ms(void);
int	ft_usleep(size_t milliseconds);
void crazy_print(t_philos *philo);

#endif