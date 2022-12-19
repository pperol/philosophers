/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:15:52 by pperol            #+#    #+#             */
/*   Updated: 2022/12/13 14:09:16 by pperol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_tamagotchies(t_setup *setup, t_tama **tamagotchies)
{
	int	i;

	i = 0;
	*tamagochies = malloc(sizeof(t_tama) * setup->nbr_of_philosophers);
	if (*tamagotchies == NULL)
		return (1);
	while (i < setup->nbr_of_philosophers)
	{
		(*tama)[i].bib_nbr = NULL;
		(*tama)[i].fork_index = i + 1;
		(*tama)[i].active = "faux";
		...
		i++;
	}
	setup->initialized.philos_init = 1;
	return (0);
}

int ft_kill_tamagotchies(t_tama tamagotchi)
{
	int i;
	
	i = 0;
	while (tamagochi.bib_nbr)
		
	return (1);
}
