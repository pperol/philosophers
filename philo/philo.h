/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:14:53 by pperol            #+#    #+#             */
/*   Updated: 2023/02/01 17:26:29 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <errno.h>
# include <pthread.h>
# include <stdio.h>

# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"
# define RST "\e[0m"

# define ERR_SET "Error: invalid argument(s)\n"
# define ERR_SET_NBR "Error: invalid number of arguments\n"
# define ERR_MEM "Error: memory allocation failure\n"
# define ERR_THR "Error: Failed to create thread for philosopher %d\n"
# define ERR_GEN "Error\n"
# define MSG_THINK "is thinking\n"
# define MSG_FORK "has taken a fork\n"
# define MSG_EAT "is eating\n"
# define MSG_SLEEP "is sleeping\n"
# define MSG_DIED "died\n"

# define GRAB_FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5

typedef struct s_data
{
	long			firststamp;
	int				so_lonely;
	int				number_of_philos;
	int				dinner_is_over;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				times_must_eat;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	lock_dinner;
}	t_data;

typedef struct s_philo
{
	long			lastsupper;
	pthread_mutex_t	*fork_right;
	t_data			*data;
	int				name;
	int				meals;
	pthread_t		thread;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	lock_supper;
	pthread_mutex_t	lock_meals;
}	t_philo;

/* Utils */
int		ft_isdigit(int c);
long	ft_atol(const char *str);
long	timestamp(void);
long	timenow(long firststamp);
int		ft_usleep(t_data *data, long time_in_ms);

/* Parsing & initialization */
void	check_args_type(int ac, char **av);
void	check_args_number(int ac);
void	init_args(int ac, char **av, t_data *data);
void	init_data(t_data *data);
void	init_philos(int n, t_data *data, t_philo **philo);

/* Philosophers state */
void	print_act(t_philo *philo, int act);
void	*eats_alone(t_philo *philo);
void	eats(t_philo *philo);
void	sleeps(t_philo *philo);
void	thinks(t_philo *philo);

/* Meals state */
int		get_meals(t_philo *philo);
void	set_meals(t_philo *philo);
int		get_last_meal(t_philo *philo);
void	set_last_meal(t_philo *philo);

/* Philosoper ends */
void	finish_dinner(t_philo *philo);
int		dinner_is_over(t_philo *philo);
int		all_philos_ate(t_philo *philo);

/* Philosophers */
void	*routine(void *ptr);
void	*monitor(void *ptr);
int		philosophers_start(int n, t_philo *philo);

#endif
