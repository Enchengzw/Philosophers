/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:53:42 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/15 13:28:58 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clean_mutexes(pthread_mutex_t *forks, int index)
{
	while (index > 0)
	{
		if (pthread_mutex_destroy(&(forks[index])) != 0)
		{
			printf("Mutex destruction failure\n");
			return ;
		}
		index--;
	}
}

void	ft_clean_forks(t_philo *philo, t_params *params)
{
	int	index;

	while (index < params->quantity)
	{
		if (pthread_mutex_destroy(philo[index].r_fork) != 0)
		{
			printf("Mutex destruction failure\n");
			return ;
		}
		printf("index %d quantity %d\n", index, params->quantity);
		index++;
	}
}

void	ft_free_all(t_program *program, t_params *param)
{
	ft_clean_forks(program->philos, param);
	free(program->forks);
	free(program->philos);
	free(param);
	free(program);
}
