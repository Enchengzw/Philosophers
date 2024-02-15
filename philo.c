/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:49:02 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/15 13:18:26 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_set_program_variables(t_program *program, t_params *params)
{
	int	index;

	index = 0;
	(program->philos)->dead = &program->dead_flag;
	if (pthread_mutex_init(&((program->meals_lock)), NULL) != 0)
		return (ft_clean_forks(program->philos, params), 0);
	while (index < params->quantity)
	{
		((program->philos)[index]).dead = &program->dead_flag;
		((program->philos)[index]).meals_lock = &program->meals_lock;
		index++;
	}
	return (1);
}

int	ft_get_params(t_params *params, char **argv)
{
	int	flag;

	flag = 0;
	params->quantity = ft_safe_atoi(argv[1], &flag);
	if (flag || params->quantity <= 0)
		return (0);
	params->time_to_die = ft_safe_atoi(argv[2], &flag);
	if (flag || params->time_to_die <= 0)
		return (0);
	params->time_to_eat = ft_safe_atoi(argv[3], &flag);
	if (flag || params->time_to_eat <= 0)
		return (0);
	params->time_to_sleep = ft_safe_atoi(argv[4], &flag);
	if (flag || params->time_to_sleep <= 0)
		return (0);
	if (argv[5])
		params->eat_limit = ft_safe_atoi(argv[5], &flag);
	else
		params->eat_limit = INT_MAX;
	if (flag || params->eat_limit <= 0)
		return (0);
	params->time = get_current_time();
	return (1);
}

void	ft_join_philos(t_program *program)
{
	int		index;
	t_philo	*philo;

	index = 0;
	while (index < program->quantity)
	{
		philo = &((program->philos)[index]);
		if (pthread_join(philo->thread, NULL) != 0)
		{
			printf("Error joining thread\n");
			program->dead_flag = 1;
			break ;
		}
		index++;
	}
}

void	ft_create_threads(t_program *program, t_params *params)
{
	int		index;
	t_philo	*philo;

	index = 0;
	while (index < params->quantity)
	{
		philo = &((program->philos)[index]);
		if (pthread_create(&(philo->thread), NULL, ft_philo_routine,
				(void *)philo))
		{
			printf("Error creating thread\n");
			program->dead_flag = 1;
			break ;
		}
		index++;
	}
	ft_create_handler(program);
	ft_join_philos(program);
}

int	main(int argc, char **argv)
{
	t_program	*program;
	t_params	*params;

	program = (t_program *)malloc(sizeof(t_program));
	params = (t_params *)malloc(sizeof(t_params));
	if (!ft_error_check(argc, argv))
		return (free(program), free(params), 0);
	if (!ft_get_params(params, argv))
		return (free(program), free(params), printf("Argument error\n"), 0);
	program->forks = ft_initialize(params, &program->philos);
	if (!ft_set_program_variables(program, params))
		return (ft_free_all(program, params), 0);
	program->quantity = params->quantity;
	program->num_times_to_eat = params->eat_limit;
	ft_create_threads(program, params);
	ft_free_all(program, params);
	return (0);
}
