/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:05:16 by ezhou             #+#    #+#             */
/*   Updated: 2024/01/30 13:40:50 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*list;

	list = malloc(count * size);
	if (!list)
		return (NULL);
	memset(list, 0, count * size);
	return (list);
}

long	ft_atoi(char *nptr)
{
	long	result;
	int		index;
	int		minus;

	minus = 1;
	result = 0;
	index = 0;
	while ((nptr[index] >= 9 && nptr[index] <= 13) || nptr[index] == 32)
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
			minus = -1;
		index += 1;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result = result * 10 + (nptr[index++] - '0');
	}
	return (result * minus);
}
