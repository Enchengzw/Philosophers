/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:58:03 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/07 17:37:52 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_initialize_one(t_philo *philo, t_params *params, int id,
		pthread_mutex_t *forks)
{
	philo->id = id;
	philo->time_to_die = params->time_to_die;
	philo->time_to_eat = params->time_to_eat;
	philo->time_to_sleep = params->time_to_sleep;
	philo->num_of_philos = params->quantity;
	philo->num_times_to_eat = params->eat_limit;
	philo->r_fork = &(forks[id]);
	if (id != (params->quantity - 1))
		philo->l_fork = &(forks[id + 1]);
	else
		philo->l_fork = &(forks[0]);
	philo->initial_time = params->time;
	philo->eating = 0;
	philo->meals_eaten = 0;
	philo->last_meal = 0;
	philo->write_lock = 0;
	philo->dead_lock = 0;
	philo->meal_lock = 0;
	philo->dead = 0;
	philo->thread = NULL;
}

int	ft_initialize_forks(pthread_mutex_t *forks, int quantity)
{
	int	index;

	index = 0;
	while (index < quantity)
	{
		if (pthread_mutex_init(&(forks[index]), NULL) != 0)
		{
			ft_clean_mutexes(forks, index - 1);
			return (printf("Mutex initialization error\n"), 0);
		}
		index++;
	}
	return (1);
}

void	ft_initialize_struct(t_philo *philos, t_params *params,
		pthread_mutex_t *forks)
{
	int	index;

	index = 0;
	while (index < params->quantity)
	{
		ft_initialize_one(&(philos[index]), params, index, forks);
		index++;
	}
}

t_philo	*ft_initialize(t_params *params)
{
	t_philo			*philos;
	pthread_mutex_t	*forks;

	forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t),
			(params->quantity + 1));
	philos = (t_philo *)ft_calloc(sizeof(t_philo), (params->quantity + 1));
	if (!ft_initialize_forks(forks, params->quantity))
		return (free(philos), free(forks), 0);
	ft_initialize_struct(philos, params, forks, time);
	return (philos);
}
