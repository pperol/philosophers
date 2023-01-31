/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:59:14 by pperol            #+#    #+#             */
/*   Updated: 2023/01/31 14:18:35 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(const char *str)
{
	long int	sign;
	long int	res;

	while ((*str && *str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	res = 0;
	while (*str && ft_isdigit(*str))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}

long	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	timenow(long firststamp)
{
	return (timestamp() - firststamp);
}

int	ft_usleep(t_data *datas, long time_in_ms)
{
	long	end_time;

	end_time = timestamp() + time_in_ms;
	while (timestamp() < end_time)
	{
		pthread_mutex_lock(&datas->lock_dinner);
		if (datas->dinner_is_over != 0)
		{
			pthread_mutex_unlock(&datas->lock_dinner);
			return (-1);
		}
		pthread_mutex_unlock(&datas->lock_dinner);
		usleep(1000);
	}
	return (0);
}
