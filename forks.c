/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:04:10 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/16 17:01:14 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_is_taking_r_fork(t_philo *philo)
{
	if (!*(philo->dead))
	{
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_lock(philo->r_fork);
		if (!pthread_mutex_lock(philo->dead_lock) && !*(philo->dead))
			ft_fork_print(philo);
		else
			pthread_mutex_unlock(philo->dead_lock);
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
	if (!*(philo->dead))
	{
		pthread_mutex_unlock(philo->dead_lock);
		if (philo->l_fork == philo->r_fork)
		{
			ft_usleep(philo->time_to_die);
			pthread_mutex_unlock(philo->r_fork);
			return ;
		}
		pthread_mutex_lock(philo->l_fork);
		if (!pthread_mutex_lock(philo->dead_lock) && !*(philo->dead))
			ft_fork_print(philo);
		else
			pthread_mutex_unlock(philo->dead_lock);
	}
	else
		pthread_mutex_unlock(philo->dead_lock);
	if (!pthread_mutex_lock(philo->dead_lock) && *(philo->dead))
	{
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_unlock(philo->r_fork);
		return (pthread_mutex_unlock(philo->l_fork), ft_0());
	}
	else
		pthread_mutex_unlock(philo->dead_lock);
}
