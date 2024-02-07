/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:16:44 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/06 17:37:23by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

size_t	ft_current_run_time(size_t old_time)
{
	return (get_current_time() - old_time);
}

void	ft_do_something(t_philo *philo, size_t miliseconds)
{
	size_t	elapsed_time;

	elapsed_time = 0;
	while (!(philo->dead) && elapsed_time < miliseconds)
	{
		if (!(philo->dead) && (miliseconds - elapsed_time) > 10)
		{
			ft_usleep(10);
			elapsed_time += 10;
		}
		else if (!(philo->dead) && (miliseconds - elapsed_time) < 10)
		{
			ft_usleep(miliseconds - elapsed_time);
			elapsed_time += (miliseconds - elapsed_time);
		}
	}
}

void	philo_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!(*philo->dead))
	{
		if (!*(philo->dead))
			ft_is_taking_fork(philo);
		if (!*(philo->dead))
			ft_is_eating(philo);
		if (!*(philo->dead))
			ft_is_sleeping(philo);
	}
}