/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:49:02 by ezhou             #+#    #+#             */
/*   Updated: 2024/01/30 16:37:52 by ezhou            ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	t_philo		*philo_lst;
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
	ft_get_params(params, argv);
 	if (!ft_error_check(argc, argv));
		return (0);
	ft_initialize(params, philo_lst); 
	return (0);
}
