/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:04:10 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/15 18:16:51 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_taking_r_fork(t_philo *philo)
{
	if (!*(philo->dead))
	{
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_lock(philo->r_fork);
		ft_fork_print(philo);
	}
	else
		pthread_mutex_unlock(philo->dead_lock);
	if (!pthread_mutex_lock(philo->dead_lock) && *(philo->dead))
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->dead_lock);
		return ;
	}
	else
		pthread_mutex_unlock(philo->dead_lock);
}

void	ft_is_taking_l_fork(t_philo *philo)
{
	if (!pthread_mutex_lock(philo->dead_lock) && !*(philo->dead))
	{
		pthread_mutex_unlock(philo->dead_lock);
		if (philo->l_fork == philo->r_fork)
		{
			usleep(philo->time_of_last_meal);
			return ;
		}
		pthread_mutex_lock(philo->l_fork);
		ft_fork_print(philo);
	}
	else
		pthread_mutex_unlock(philo->dead_lock);
	if (!pthread_mutex_lock(philo->dead_lock) && *(philo->dead))
	{
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	else
		pthread_mutex_unlock(philo->dead_lock);
}
