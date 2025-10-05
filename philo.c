/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:43:22 by vvazzs            #+#    #+#             */
/*   Updated: 2025/10/05 18:18:30 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo *philos(void)
{
    static t_philo philosophers;

    return (&philosophers);
}

void get_values(t_init *init, char **argv)
{
    if (init)
    {
    init->number_of_philo = ft_atoi(argv[1]);
    init->time_to_die = ft_atoi(argv[2]);
    init->time_to_eat = ft_atoi(argv[3]);
    init->time_to_sleep = ft_atoi(argv[4]);
    if (argv[5])
        init->minimum_eat_times = ft_atoi(argv[5]);
    else
        init->minimum_eat_times = 0;
    }
    printf("Number of philo = %d\n", init->number_of_philo);
    printf("Time to die = %d\n", init->time_to_die);
    printf("Time to eat = %d\n", init->time_to_eat);
    printf("Time to sleep = %d\n", init->time_to_sleep);
    printf("Minimum times to eat= %d\n", init->minimum_eat_times);
    
}

int main(int argc, char *argv[])
{
    t_philo *main_philo = philos();
    
    if (argc < 5 || argc > 6)
        return (printf("Invalid number of args\n"), 0);
    main_philo->init = malloc(sizeof(t_init));
    if (!main_philo->init)
        return (printf("can't alloc memory for that\n"), 0);
    get_values(philos()->init, argv);
    free(main_philo->init);
    return (0);
}