/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:53:42 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/16 12:36:18 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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

	index = 0;
	while (index < params->quantity)
	{
		if (pthread_mutex_destroy(philo[index].r_fork) != 0)
		{
			printf("Mutex destruction failure\n");
			return ;
		}
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
