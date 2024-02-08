/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:55:26 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/08 17:09:36 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_is_thinking(t_philo *philo)
{
	printf(BLUE_TEXT "%zu %d is thinking" RESET_TEXT "\n",
		ft_current_run_time(philo->initial_time), philo->id);
}

void	ft_is_taking_fork(t_philo *philo)
{
	if (!*(philo->dead))
		ft_is_thinking(philo);
	if (!*(philo->dead))
	{
		pthread_mutex_lock(philo->r_fork);
		printf(GREEN_TEXT "%zu %d is taking a fork" RESET_TEXT "\n",
			ft_current_run_time(philo->initial_time), philo->id);
	}
	if (!*(philo->dead))
	{
		pthread_mutex_lock(philo->l_fork);
		printf(GREEN_TEXT "%zu %d is taking a fork" RESET_TEXT "\n",
			ft_current_run_time(philo->initial_time), philo->id);
	}
}

void	ft_is_eating(t_philo *philo)
{
	printf(DARK_GREEN_TEXT "%zu %d is eating" RESET_TEXT "\n",
		ft_current_run_time(philo->initial_time), philo->id);
	ft_do_something(philo, philo->time_to_eat);
	philo->meals_eaten += 1;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	ft_is_sleeping(t_philo *philo)
{
	printf(ORANGE_TEXT "%zu %d is sleeping" RESET_TEXT "\n",
		ft_current_run_time(philo->initial_time), philo->id);
	ft_do_something(philo, philo->time_to_sleep);
}

void	ft_is_dead(t_philo *philo)
{
	printf(RED_TEXT "%zu %d has died" RESET_TEXT "\n",
		ft_current_run_time(philo->initial_time), philo->id);
}
