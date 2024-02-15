/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:11:28 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/15 18:10:44 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_fork_print(t_philo *philo)
{
	printf(GREEN_TEXT "%zu %d is taking a fork" RESET_TEXT "\n",
		ft_current_run_time(philo->initial_time), philo->id);
}

void	ft_0(void)
{
	return ;
}
