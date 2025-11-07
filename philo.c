/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:43:22 by vvazzs            #+#    #+#             */
/*   Updated: 2025/11/07 22:07:49 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	_initialize_stuff(t_general *gen, int argc, char *argv[])
{
	int	i;

	if (args_checker(argc, argv) != 0)
		return (1);
	gen->number_of_philo = ft_atol(argv[1]);
	gen->init = malloc(sizeof(t_init));
	if (!gen->init)
		return (printf("Couldn't load init\n"), 1);
	gen->philo = calloc(gen->number_of_philo, sizeof(t_philos));
	if (!gen->philo)
		return (printf("Couldn't load main struct\n"), 1);
	gen->threads = malloc(sizeof(pthread_t) * gen->number_of_philo);
	if (!gen->threads)
		return (printf("Couldn't allocate threads\n"), 1);
	i = 0;
	while (i < gen->number_of_philo)
	{
		gen->philo[i].id = i;
		gen->philo[i].init = gen->init;
		i++;
	}
	init_values(gen->philo, argv);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_general	gen;

	if (_initialize_stuff(&gen, argc, argv))
		return (1);
	if (gen.philo->init->time_to_die < gen.philo->init->time_to_eat
		|| gen.philo->init->time_to_die < gen.philo->init->time_to_sleep)
		return (handle_early_death_case_all(gen.philo), 1);
	if (create_threads(gen.number_of_philo, gen.threads, gen.philo) != 0)
		return (perror("Not working right now\n"), 1);
	monitor(gen.philo);
	printf("====exiting====\n");
	if (join_threads(gen.number_of_philo, gen.threads) != 0)
		return (perror("Failure\n"), 1);
	super_duper_hiper_free(gen.philo, gen.init, gen.threads);
	return (0);
}
