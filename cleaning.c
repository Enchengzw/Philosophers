/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:53:42 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/06 12:58:05 by ezhou            ###   ########.fr       */
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
