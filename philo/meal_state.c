/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:27:22 by pperol            #+#    #+#             */
/*   Updated: 2023/01/31 14:47:37 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_meals(t_philo *philo)
{
	int	meals;

	pthread_mutex_lock(&philo->lock_meals);
	meals = philo->meals;
	pthread_mutex_unlock(&philo->lock_meals);
	return (meals);
}

void	set_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_meals);
	philo->meals++;
	pthread_mutex_unlock(&philo->lock_meals);
}

int	get_last_meal(t_philo *philo)
{
	long	last_meal;

	pthread_mutex_lock(&philo->lock_supper);
	last_meal = philo->lastsupper;
	pthread_mutex_unlock(&philo->lock_supper);
	return (last_meal);
}

void	set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_supper);
	philo->lastsupper = timenow(philo->data->firststamp);
	pthread_mutex_unlock(&philo->lock_supper);
}
