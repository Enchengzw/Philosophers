/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:55:26 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/15 18:05:08 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_thinking(t_philo *philo)
{
	printf(BLUE_TEXT "%zu %d is thinking" RESET_TEXT "\n",
		ft_current_run_time(philo->initial_time), philo->id);
}

void	ft_is_eating(t_philo *philo)
{
	pthread_mutex_unlock(philo->dead_lock);
	printf(DARK_GREEN_TEXT "%zu %d is eating" RESET_TEXT "\n",
		ft_current_run_time(philo->initial_time), philo->id);
	ft_do_something(philo, philo->time_to_eat);
	pthread_mutex_lock(philo->meals_lock);
	philo->meals_eaten += 1;
	philo->time_of_last_meal = get_current_time();
	pthread_mutex_unlock(philo->meals_lock);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	ft_is_sleeping(t_philo *philo)
{
	if (!*(philo->dead))
		printf(ORANGE_TEXT "%zu %d is sleeping" RESET_TEXT "\n",
			ft_current_run_time(philo->initial_time), philo->id);
	if (!*(philo->dead))
	{
		pthread_mutex_unlock(philo->dead_lock);
		ft_do_something(philo, philo->time_to_sleep);
	}
	else
		pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_lock(philo->dead_lock);
	if (!*(philo->dead))
	{
		ft_is_thinking(philo);
	}
	pthread_mutex_unlock(philo->dead_lock);
}

void	ft_is_dead(t_philo *philo)
{
	printf(RED_TEXT "%zu %d has died" RESET_TEXT "\n",
		ft_current_run_time(philo->initial_time), philo->id);
}
