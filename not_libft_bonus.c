/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_libft_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:14:11 by ezhou             #+#    #+#             */
/*   Updated: 2024/01/30 17:03:16 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_initialize_one(t_philo *node)
{
	node->thread = NULL;
	node->id = 0;
	node->eating = 0;
	node->meals_eaten = 0;
	node->last_meal = 0;
	node->time_to_die = 0;
	node->time_to_eat = 0;
	node->time_to_sleep = 0;
	node->start_time = 0;
	node->num_of_philos = 0;
	node->num_times_to_eat = 0;
	node->dead = 0;
	node->r_fork = 0;
	node->l_fork = 0;
	node->write_lock = 0;
	node->dead_lock = 0;
	node->meal_lock = 0;
	node->next = 0;
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstadd_back(&((*lst)->next), new);
}

t_philo	*ft_lstnew(t_params *params)
{
	t_philo	*node;

	node = (t_philo *)malloc(sizeof(t_philo));
	if (!node)
		return (NULL);
	node->next = NULL;
	ft_initialize_one(node);
	return (node);
}
