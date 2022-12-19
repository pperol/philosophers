/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:15:19 by pperol            #+#    #+#             */
/*   Updated: 2022/12/12 16:51:49 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
number_of_philosophers 
time_to_die 
time_to_eat 
time_to_sleep
number_of_times_each_philosopher_must_eat
*/

// one thread == one function!!

int ft_first_fork_on_the_table(t_tama tamagotchi)
{
	t_tama *left_tamagotchi;
	t_tama *right_tamagotchi;

	left_tamagotchi == tamagotchi[tamagotchi.bib_nbr + 1];
	right_tamagotchi == tamagotchi[tamagotchi.bib_nbr - 1];
	if 
}

t_bool	ft_takes_a_first_fork(t_tama tamagotchi)
{
	int times_stamp_in_ms;

	if (ft_is_alive(tamagotchi) == "vrai"
		&& tamagotchi->is_satiated == "faux"
		&& tamagotchi->is_thinking == "vrai"
		&& tamagotchi->has_taken_a_fork == "faux";
		&& ft_first_fork_is_on_the_table(tamagotchi) == "vrai")
	{
		tama->has_taken_a_fork == "vrai";
		printf("%d: %d has taken a first fork\n", 
			timestamp_in_ms, tama->bib_nbr)
		return(vrai);
	}
	return(faux);
}

t_bool	ft_takes_a_second_fork(t_tama tamagotchi)
{
	int times_stamp_in_ms;

	if (ft_is_alive(tamagotchi) == "vrai"
		&& tamagotchi->has_taken_two_forks == "faux"
		&& tamagotchi->has_taken_a_fork == "vrai"
		&& ft_second_fork_is_on_the_table(tamagotchi) == "vrai")
	{
		tama->has_taken_two_forks == "vrai";
		printf("%d: %d has taken a second fork\n", 
			timestamp_in_ms, tama->bib_nbr)
		return(vrai);
	}
	return(faux);
}

t_bool	ft_tama_is_eating(t_tama tamagotchi)
{
	int times_stamp_in_ms;

	if (ft_is_alive(tamagotchi) == "vrai"
		&& tamagotchi.has_taken_a_fork == "vrai"
		&& tamagotchi.has_taken_two_forks == "vrai")
	{
		tamagotchi.is_thinking == "faux";
		tamagotchi.is_eating == "vrai";
		tamagotchi.is_alive == "vrai";
		printf("%d: %d is eating\n", timestamp_in_ms, timatama->bib_nbr)
		//usleep()
		tamagotchi.has_returned_both_forks == "vrai";
		return (vrai);
	}
	return(faux);
}

t_bool	ft_tama_is_sleeping(t_tama tamagotchi)
{
	int times_stamp_in_ms;

	timestamp_in_ms = gettimeofday();
	if (ft_is_alive(tamagotchi) == "vrai"
		&& tamagotchi.has_taken_a_fork == "vrai"
		&& tamagotchi.has_taken_two_forks == "vrai")
	{
		tamagotchi.is_thinking == "faux";
		tamagotchi.is_eating == "vrai";
		tamagotchi.is_alive == "vrai";
		printf("%d: %d is sleeping\n", timestamp_in_ms, tama->bib_nbr)
		//usleep()
		tamagotchi.is_thinking == "vrai";
		return (vrai);
	}
	return(faux);
}

int ft_check_tamagotchis_are_alive(t_tama tamagotchi, int nb_of_tamagotchies)
{
	int i;
	
	i = 1;
	while(i <= nb_of_tamagotchies)
	{
		while(tamagotchi[i - 1])
		{
			if (tamagotchi.is_alive == "vrai")
			return (1);
		}
		i++;
	}
	return (0);
}
	
int ft_check_tamagotchis_are_satiated(t_tama tamagotchi, int nb_of_tamagotchies)
{
	int i;
	
	i = 1;
	while(i <= nb_of_tamagotchies)
	{
		while(tamagotchi[i - 1])
		{
			if (tamagotchi.is_satiated == "faux")
			return (0);
		}
		i++;
	}
	return (1);
}
	
void	*my_turn(void *arg)
{
	int i = 0;
	while (i < 5)
	{
		usleep(100000);
		printf("My turn!\n");
		i++;
	}
	return(NULL);
}

void	your_turn(void)
{
	int i = 0;
	while (i < 5)
	{
		usleep(200000);
		printf("Your turn...\n");
		i++;
	}
}

int main(int ac, char *av) 
{
	pthread_t	newthread;
	

	pthread_create(&newthread, NULL, my_turn, NULL); 
	your_turn();
	pthread_join(newthread, NULL);
    return (0);
}

int main(int ac, char *av)
{
	if (ac < 2 || ac > 2)
		ft_error()
	else
		ft_init_tamagocthi();
		// check is_satiated == NULL || <= av[5]
	return (0);
}
	
