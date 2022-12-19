/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:14:53 by pperol            #+#    #+#             */
/*   Updated: 2022/12/13 13:11:00 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h> // intmax_t
# include <pthread.h> // pthread
# include <stdbool.h> // bool
# include <stdint.h> // INT_MAX/MIN
# include <stdio.h> // printf
# include <stdlib.h> // free, malloc
# include <sys/time.h> // gettimeofday
# include <unistd.h> // write, usleep

/*

number_of_philosophers == number_of_forks 
time_to_die (=> The death timer is reset *at the beginning of eating*)
time_to_eat => number_of_forks == 2
time_to_sleep => number_of_forks == 0;
number_of_times_each_philosopher_must_eat

◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died

Afin d’empêcher les philosophes de dupliquer les fourchettes, vous devez protéger
leur état en mémoire avec un mutex pour chacune d’entre elle.

memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
*/

/*
**** printf
*/
#include <stdio.h>

/*
*** void *memset(void *s, int c, size_t n);
*** The  memset() function fills the first n bytes of the memory area 
*** pointed to by s with the constant byte c.
*/
#include <string.h>

/*
*** void *malloc(size_t size);
*** The malloc() function allocates size bytes and returns a pointer 
	to the allocated memory.  The memory is not initialized.  
	If size is 0, then malloc() returns either NULL, or a unique pointer 
	value that can later be successfully passed to free().
*/

/*
**** write, usleep
**** int usleep(useconds_t usec);
**** The usleep() function suspends execution of the calling thread 
**** for (at least) usec microseconds. The sleep may be lengthened slightly 
**** by any system  activity  or  by  the time spent processing the call 
**** or by the granularity of system timers.
*/
#include <unistd.h>

/*
**** gettimeofday
**** int gettimeofday(struct timeval *tv, struct timezone *tz);
**** The  functions gettimeofday() and settimeofday() can get and set 
**** the time as well as a timezone.
**** The tv argument is a struct timeval (as specified in <sys/time.h>):
           struct timeval {
               time_t      tv_sec;     / seconds /
               suseconds_t tv_usec;    / microseconds /
           };
**** and gives the number of seconds and microseconds since the 
**** Epoch (see time(2)).
*/
#include <stdio.h>

#include <stdlib.h>

/*
*** THREADS
*** pthread_create, 
	pthread_detach, 
	pthread_join, 
	pthread_mutex_init,
	pthread_mutex_destroy, 
	pthread_mutex_lock,
	pthread_mutex_unlock
*/
#include <pthread.h>

# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"

# define ERR_SET "Error: invalid argumenti(s) provided\n"
# define ERR_SET_NBR "Error: invalid number of arguments\n"
# define ERR_GEN "Error\n"
# define MSG_ENOUGH " has eaten enough"
# define MSG_ONE_FORK " has taken a first fork"
# define MSG_TWO_FORKS " has taken a second fork"
# define MSG_EAT " is eating"
# define MSG_SLEEP " is sleeping"
# define MSG_THINK " is thinking"
# define MSG_DIED " died, program ends."
# define LEFT 0
# define RIGHT 1

typedef enum {
	vrai,
	faux	
}	t_bool;

typedef struct	s_setup
{
	size_t	nbr_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	size_t	number_of_times_each_philosopher_must_eat;
}	t_setup;

typedef struct 	s_tamagotchi
{
	size_t	bib_nbr;
	size_t	fork_index;
	size_t	msec_to_eat;
	size_t	msec_to_sleep;
	size_t	meal_index;
	size_t	time_to_live;
	t_bool	is_satiated;
	t_bool 	has_taken_a_fork;
	t_bool 	has_taken_two_forks;
	t_bool 	is_eating;
	t_bool 	has_returned_both_forks;
	t_bool	is_thinking;
	t_bool	is_sleeping;
	t_bool	is_alive;
}	t_tama;

typedef	struct s_datas
{
	
	
}	t_dashboard;

#endif
