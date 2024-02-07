/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:55:26 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/07 12:00:30 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_is_thinking(t_philo *philo)
{
	printf(BLUE_TEXT "%d %d is thinking" RESET_TEXT "\n", philo->id,
		ft_time_elapsed(philo->initial_time));
}

void	ft_is_taking_fork(t_philo *philo)
{
	printf(GREEN_TEXT "%d is taking a fork" RESET_TEXT "\n", philo->id,
		ft_time_elapsed(philo->initial_time));
}

void	ft_is_sleeping(t_philo *philo)
{
	printf(ORANGE_TEXT "%d is sleeping" RESET_TEXT "\n", philo->id,
		ft_time_elapsed(philo->initial_time));
}

void	ft_is_dead(t_philo *philo)
{
	printf(RED_TEXT "%d has died" RESET_TEXT "\n", philo->id,
		ft_time_elapsed(philo->initial_time));
}
