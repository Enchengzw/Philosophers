/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:49:02 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/08 17:17:45 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	set_program_variables(t_program *program, t_params *params)
{
	(program->philos)->dead = &program->dead_flag;
	if (pthread_mutex_init(&((program->write_lock)), NULL) != 0)
		return (ft_clean_forks(program->philos, params->quantity), 0);
	return (1);
}

void	ft_get_params(t_params *params, char **argv)
{
	params->quantity = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		params->eat_limit = ft_atoi(argv[5]);
	else
		params->eat_limit = INT_MAX;
	params->time = get_current_time();
}

void	leaks()
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_program	*program;
	t_params	*params;

	atexit(leaks);
	program = (t_program *)malloc(sizeof(t_program));
	params = (t_params *)malloc(sizeof(t_params));
	if (!ft_error_check(argc, argv))
		return (0);
	ft_get_params(params, argv);
	ft_initialize(params, &program->philos);
	//if (!ft_set_program_variables(program, params))
		//return (free(params), ft_free_all(program), 0);
	//printer(program->philos);
	//printer(&program->philos[1]);
	//printer(&program->philos[2]);
	return (0);
}
