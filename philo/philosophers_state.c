/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_state.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:06:16 by pperol            #+#    #+#             */
/*   Updated: 2023/01/31 15:03:32 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_act(t_philo *philo, int act)
{
	long	time;

	pthread_mutex_lock(&philo->data->lock_print);
	time = timenow(philo->data->firststamp);
	if (act == GRAB_FORK && !dinner_is_over(philo))
		printf("%ld %d %s", time, philo->name, MSG_FORK);
	else if (act == EATING && !dinner_is_over(philo))
		printf("%ld %d %s", time, philo->name, MSG_EAT);
	else if (act == SLEEPING && !dinner_is_over(philo))
		printf("%ld %d %s", time, philo->name, MSG_SLEEP);
	else if (act == THINKING && !dinner_is_over(philo))
		printf("%ld %d %s", time, philo->name, MSG_THINK);
	else if (act == DIED)
		printf("%ld %d %s", time, philo->name, MSG_DIED);
	pthread_mutex_unlock(&philo->data->lock_print);
}

void	*eats_alone(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_right);
	print_act(philo, GRAB_FORK);
	pthread_mutex_unlock(philo->fork_right);
	return (NULL);
}

void	eats(t_philo *philo)
{
	if (philo->name % 2 == 0)
	{
		pthread_mutex_lock(&philo->fork_left);
		print_act(philo, GRAB_FORK);
		pthread_mutex_lock(philo->fork_right);
		print_act(philo, GRAB_FORK);
	}
	else
	{
		pthread_mutex_lock(philo->fork_right);
		print_act(philo, GRAB_FORK);
		pthread_mutex_lock(&philo->fork_left);
		print_act(philo, GRAB_FORK);
	}
	print_act(philo, EATING);
	set_last_meal(philo);
	set_meals(philo);
	ft_usleep(philo->data, philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

void	sleeps(t_philo *philo)

{
	print_act(philo, SLEEPING);
	ft_usleep(philo->data, philo->data->time_to_sleep);
}

void	thinks(t_philo *philo)
{
	print_act(philo, THINKING);
	ft_usleep(philo->data, philo->data->time_to_think);
}
