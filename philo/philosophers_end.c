/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:37:12 by pperol            #+#    #+#             */
/*   Updated: 2023/01/31 12:38:13 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	finish_dinner(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock_dinner);
	philo->data->dinner_is_over = 1;
	pthread_mutex_unlock(&philo->data->lock_dinner);
}

int	dinner_is_over(t_philo *philo)
{
	int	dinner_is_over;

	pthread_mutex_lock(&philo->data->lock_dinner);
	dinner_is_over = 0;
	if (philo->data->dinner_is_over)
		dinner_is_over = philo->data->dinner_is_over;
	pthread_mutex_unlock(&philo->data->lock_dinner);
	return (dinner_is_over);
}

int	all_philos_ate(t_philo *philo)
{
	int	i;
	int	dinner;

	dinner = 0;
	i = 0;
	while (i < philo->data->number_of_philos)
	{
		if (get_meals(&philo[i]) == philo[i].data->times_must_eat)
			dinner++;
		i++;
	}
	if (dinner == philo->data->number_of_philos)
		return (1);
	return (0);
}
