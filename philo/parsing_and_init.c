/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_and_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:32:29 by pperol            #+#    #+#             */
/*   Updated: 2023/01/31 15:04:01 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_args_type(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j])
				|| ft_atol(av[i]) > 2147483647
				|| ft_atol(av[i]) == 0)
			{
				printf(ERR_SET);
				exit (EXIT_FAILURE);
			}
			j++;
		}
	}
}

void	check_args_number(int ac)
{
	if (ac > 6)
		printf(ERR_SET_NBR);
	else if (ac < 5)
		printf(ERR_SET_NBR);
	else
		return ;
	exit (EXIT_FAILURE);
}

void	init_args(int ac, char **av, t_data *data)
{
	check_args_type(ac, av);
	check_args_number(ac);
	data->number_of_philos = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	if (ft_atol(av[4]) > ft_atol(av[2]))
		data->time_to_sleep = ft_atol(av[2]);
	else
		data->time_to_sleep = ft_atol(av[4]);
	if ((ft_atol(av[3]) > ft_atol(av[4])) || ft_atol(av[2]) > 1000)
		data->time_to_think = ft_atol(av[3]) - ft_atol(av[4]);
	else
		data->time_to_think = (ft_atol(av[2]) - ft_atol(av[3])
				- ft_atol(av[4])) / 2;
	data->times_must_eat = -1;
	if (ac == 6)
		data->times_must_eat = ft_atol(av[5]);
}

void	init_data(t_data *data)
{
	if (data->number_of_philos == 1)
		data->so_lonely = 1;
	else
		data->so_lonely = 0;
	data->dinner_is_over = 0;
	data->firststamp = 0;
	pthread_mutex_init(&data->lock_print, NULL);
	pthread_mutex_init(&data->lock_dinner, NULL);
}

void	init_philos(int n, t_data *data, t_philo **philo)
{
	int		i;
	t_philo	*philo_array;

	philo_array = malloc(sizeof(t_philo) * n + 1);
	if (!philo_array)
	{
		printf(ERR_MEM);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < n)
	{
		pthread_mutex_init(&philo_array[i].lock_supper, NULL);
		pthread_mutex_init(&philo_array[i].lock_meals, NULL);
		pthread_mutex_init(&philo_array[i].fork_left, NULL);
		if (i != n - 1)
			philo_array[i].fork_right = &philo_array[i + 1].fork_left;
		philo_array[i].name = i + 1;
		philo_array[i].meals = 0;
		philo_array[i].lastsupper = 0;
		philo_array[i].data = data;
		i++;
	}
	philo_array[i - 1].fork_right = &philo_array[0].fork_left;
	*philo = philo_array;
}
