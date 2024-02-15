/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:16:44 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/15 18:10:33 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_current_run_time(size_t old_time)
{
	return (get_current_time() - old_time);
}

void	ft_wait_ms(size_t *elapsed_time, size_t ms)
{
	if ((ms - *elapsed_time) >= 10)
	{
		ft_usleep(10);
		*elapsed_time += 10;
	}
	else if ((ms - *elapsed_time) < 10)
	{
		ft_usleep(ms - *elapsed_time);
		*elapsed_time += (ms - *elapsed_time);
	}
}

void	ft_do_something(t_philo *philo, size_t miliseconds)
{
	size_t	elapsed_time;

	elapsed_time = 0;
	while (!pthread_mutex_lock(philo->dead_lock) && !*(philo->dead)
		&& elapsed_time < miliseconds)
	{
		if (!*philo->dead)
		{
			pthread_mutex_unlock(philo->dead_lock);
			ft_wait_ms(&elapsed_time, miliseconds);
		}
		else
			pthread_mutex_unlock(philo->dead_lock);
	}
	pthread_mutex_unlock(philo->dead_lock);
}

void	*ft_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->id % 2 == 0)
		usleep(500);
	while (!pthread_mutex_lock(philo->dead_lock) && !(*philo->dead))
	{
		if (!*(philo->dead))
			ft_is_taking_r_fork(philo);
		else
			pthread_mutex_unlock(philo->dead_lock);
		if (pthread_mutex_lock(philo->dead_lock) && !*(philo->dead))
			ft_is_taking_l_fork(philo);
		else
			pthread_mutex_unlock(philo->dead_lock);
		if (!pthread_mutex_lock(philo->dead_lock) && !*(philo->dead))
			ft_is_eating(philo);
		else
			pthread_mutex_unlock(philo->dead_lock);
		if (!pthread_mutex_lock(philo->dead_lock) && !*(philo->dead))
			ft_is_sleeping(philo);
		pthread_mutex_unlock(philo->dead_lock);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}
