/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:40:07 by pperol            #+#    #+#             */
/*   Updated: 2023/02/01 17:47:49 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->name % 2)
		usleep(200);
	if (philo->data->so_lonely)
		return (eats_alone(philo));
	while (!dinner_is_over(philo))
	{
		eats(philo);
		if (get_meals(philo) == philo->data->times_must_eat)
			return (NULL);
		sleeps(philo);
		thinks(philo);
	}
	return (NULL);
}

void	*monitor(void *ptr)
{
	int		i;
	long	current_time;
	long	time_to_die;
	t_philo	*philos;

	philos = (t_philo *)ptr;
	time_to_die = philos->data->time_to_die;
	while (!all_philos_ate(philos))
	{
		i = 0;
		while (i < philos->data->number_of_philos)
		{
			current_time = timenow(philos->data->firststamp);
			if ((current_time - get_last_meal(&philos[i])) > time_to_die)
			{
				finish_dinner(&philos[i]);
				print_act(&philos[i], DIED);
				return (NULL);
			}
			i++;
		}
		usleep(10000);
	}
	return (NULL);
}

int	philosophers_start(int n, t_philo *philo)
{
	int			i;
	pthread_t	monitor_thread;

	i = 0;
	philo->data->firststamp = timestamp();
	while (i < n)
	{
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		i++;
	}
	pthread_create(&monitor_thread, NULL, &monitor, philo);
	i = 0;
	while (i < n)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philos;

	init_args(ac, av, &data);
	init_data(&data);
	init_philos(data.number_of_philos, &data, &philos);
	philosophers_start(data.number_of_philos, philos);
	free(philos);
	return (0);
}
