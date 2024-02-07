/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:35:13 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/07 17:37:17 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	printer(t_philo *philo)
{
	printf("This is philo: %d\n", philo->id);
	printf("			Left fork: %p\n", philo->l_fork);
	printf("			Left fork: %p\n", philo->r_fork);
}
