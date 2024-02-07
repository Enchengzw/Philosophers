/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:49:02 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/07 12:16:50 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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

int	main(int argc, char **argv)
{
	t_philo		*philos;
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
 	if (!ft_error_check(argc, argv));
		return (0);
	ft_get_params(params, argv);
	philos = ft_initialize(params);
	
	return (0);
}
