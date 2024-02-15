/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:53:26 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/15 13:24:04 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_check(t_program *program, t_philo *philo, int *index)
{
	size_t	time;

	while (*index < program->quantity && !(program->dead_flag))
	{
		time = ft_current_run_time(philo[*index].time_of_last_meal);
		if (time >= philo->time_to_die && !(program->dead_flag))
		{
			program->dead_flag = 1;
			ft_is_dead(philo);
		}
		if (philo[*index].meals_eaten >= program->num_times_to_eat)
			program->dead_flag = 1;
		(*index)++;
	}
}

void	*ft_handler(void *arg)
{
	int			index;
	t_philo		*philo;
	t_program	*program;

	program = arg;
	philo = program->philos;
	while (!(program->dead_flag))
	{
		index = 0;
		ft_check(program, philo, &index);
		/* while (index < program->quantity && !(program->dead_flag))
		{
			time = ft_current_run_time(philo[index].time_of_last_meal);
			if (time >= philo->time_to_die && !(program->dead_flag))
			{
				program->dead_flag = 1;
				ft_is_dead(philo);
			}
			if (philo[index].meals_eaten >= program->num_times_to_eat)
				program->dead_flag = 1;
			index++;
		} */
	}
	return (0);
}

void	ft_create_handler(t_program *program)
{
	if (pthread_create(&(program->handler), NULL, ft_handler, (void *)program))
	{
		printf("Error creating handler thread\n");
		program->dead_flag = 1;
		return ;
	}
	if (pthread_join(program->handler, NULL) != 0)
	{
		printf("Error joining handler thread\n");
		program->dead_flag = 1;
		return ;
	}
}
