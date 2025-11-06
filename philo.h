/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:06:18 by vvazzs            #+#    #+#             */
/*   Updated: 2025/11/06 15:22:27 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/wait.h>
# include <termios.h>
# include <time.h>
# include <limits.h>



#define CLR_RESET   "\033[0m"
#define CLR_RED     "\033[31m"
#define CLR_GREEN   "\033[32m"
#define CLR_YELLOW  "\033[33m"
#define CLR_BLUE    "\033[34m"
#define CLR_MAGENTA "\033[35m"
#define U_INT unsigned int
typedef unsigned long long	t_time;

typedef struct s_init_vars
{
	int						food_counter;
	int						number_of_philo;
	int						minimum_eat_times;
	int						stop_simulation;
	t_time					time_to_die;
	t_time					time_to_eat;
	t_time					time_to_sleep;
	t_time					start_time;
	pthread_mutex_t			absolute_lock;
	pthread_mutex_t			death_lock;
	pthread_mutex_t			*general_forks;
	pthread_mutex_t			stop_lock;
	pthread_mutex_t			food_lock;
}							t_init;

typedef struct s_philo
{
	int						id;
	int						times_eaten;
	int						pass_away_flag;
	t_time					time_of_last_meal;
	pthread_mutex_t			death_flag;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			lock_to_message;
	t_init					*init;
}							t_philos;

long						ft_atol(const char *str);
size_t							ft_strlen(char *str);
int delivery_calculator(t_philos *philo);
void						ft_putstr_fd(int fd, char *str);
int							is_number(char *str);
void						init_values(t_philos *philo, char **argv);
int							create_threads(int number_of_philos,
								pthread_t th[number_of_philos],
								t_philos *philo);
int							join_threads(int number_of_philos,
								pthread_t th[number_of_philos]);
void						*socrates(void *arg);
void	print_message(t_philos *philo, char *str, int is_dead);
t_philos					*philos(void);
void						print_philo_values(t_philos *philo, char **argv);
int	philo_thinking(t_philos *philo);
int	philo_sleeping(t_philos *philo);
int	philo_eating(t_philos *philo);
int check_death(t_philos *philo);
void *routine_loop(void *arg);
t_time	get_current_time_ms(void);
void ft_usleep(t_time milliseconds, t_philos *philo);
void crazy_print(t_philos *philo);
int should_stop(t_philos *philo);
void print_death(t_philos *philo, char *str);


#endif