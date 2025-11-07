/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:43:22 by vvazzs            #+#    #+#             */
/*   Updated: 2025/11/07 21:56:04 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define INVALID "Invalid arguments\n"

int	last_argument_validation(char *str)
{
	int	i;

	if (is_number(str) != 0)
		return (write(2, INVALID, 19), -1);
	if (str[0] == '-' && str[0] == '\0' || str[0] == '+' && str[0] == '\0')
		return (write(2, INVALID, 19), -1);
	i = ft_atol(str);
	if (i <= 0)
		return (-1);
	return (1);
}

int	args_checker(int argc, char *argv[])
{
	int		i;
	long	check;

	i = 1;
	if (argc < 5 || argc > 6)
		return (write(2, INVALID, 19), 1);
	while (i <= 4)
	{
		check = ft_atol(argv[i]);
		if (check <= 0)
			return (write(2, INVALID, 19), 1);
		if (is_number(argv[i]) != 0)
			return (write(2, INVALID, 19), 1);
		i++;
	}
	if (argv[5] && last_argument_validation(argv[5]) == -1)
		return (1);
	i = ft_atol(argv[1]);
	if (i == 0)
		return (1);
	return (0);
}

void	monitor(t_philos *philo)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < philo->init->number_of_philo)
		{
			if (check_death(&philo[i]) == -1)
			{
				pthread_mutex_lock(&philo->init->absolute_lock);
				print_message(&philo[i], CLR_RED "died\n" CLR_RESET, 1);
				pthread_mutex_lock(&philo->init->stop_lock);
				philo->init->stop_simulation = 1;
				pthread_mutex_unlock(&philo->init->stop_lock);
				pthread_mutex_unlock(&philo->init->absolute_lock);
				return ;
			}
		}
		if (delivery_calculator(philo) != 0)
		{
			monitor_helper(philo);
			break ;
		}
		usleep(1000);
	}
}

void	handle_early_death_case_all(t_philos *philo)
{
	int	i;

	i = -1;
	print_message(&philo[0], CLR_GREEN "has taken a fork\n" CLR_RESET, 0);
	if (philo->init->number_of_philo > 1)
		print_message(&philo[0], CLR_GREEN "has taken a fork\n" CLR_RESET, 0);
	print_message(&philo[0], CLR_YELLOW "is eating\n" CLR_RESET, 0);
	ft_usleep(philo->init->time_to_die, &philo[0]);
	pthread_mutex_lock(&philo->init->absolute_lock);
	print_message(&philo[0], CLR_RED "died\n" CLR_RESET, 1);
	pthread_mutex_lock(&philo->init->stop_lock);
	philo->init->stop_simulation = 1;
	pthread_mutex_unlock(&philo->init->stop_lock);
	pthread_mutex_unlock(&philo->init->absolute_lock);
}

int	main(int argc, char *argv[])
{
	int			number_of_philo;
	pthread_t	*threads;
	t_init		*init;
	t_philos	*philo;

	if (args_checker(argc, argv) != 0)
		return (1);
	number_of_philo = ft_atol(argv[1]);
	if (!(init = malloc(sizeof(t_init))))
		return (printf("Couldn't load init\n"), -1);
	if (!(philo = calloc(sizeof(t_philos) * number_of_philo, 1)))
		return (printf("Couldn't load main struct\n"), -1);
	if (!(threads = malloc(sizeof(pthread_t) * number_of_philo)))
		return (printf("Couldn't allocate threads\n"), -1);
	for (int i = 0; i < number_of_philo; i++)
	{
		philo[i].id = i;
		philo[i].init = init;
	}
	init_values(philo, argv);
	if (philo->init->time_to_die < philo->init->time_to_eat
		|| philo->init->time_to_die < philo->init->time_to_sleep)
		return (handle_early_death_case_all(philo), 1);
	if (create_threads(number_of_philo, threads, philo) != 0)
		return (perror("Not working right now\n"), 1);
	monitor(philo);
	printf("====exiting====\n");
	if (join_threads(number_of_philo, threads) != 0)
		return (perror("Failure\n"), 1);
	pthread_mutex_destroy(&philo->init->absolute_lock);
	pthread_mutex_destroy(&philo->lock_to_message);
	free(init->general_forks);
	if (init)
		free(init);
	if (philo)
		free(philo);
	if (threads)
		free(threads);
	return (0);
}
