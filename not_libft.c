/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:05:16 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/14 17:08:06 by ezhou            ###   ########.fr       */
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

int	ft_atoi(char *nptr)
{
	int		result;
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

int	ft_safe_atoi(char *npr, int *flag)
{
	int		result;
	char	*to_compare;
	char	*aux;

	if (*npr == '+')
		aux = npr + 1;
	else
		aux = npr;
	result = ft_atoi(npr);
	to_compare = ft_itoa(result);
	if (ft_strncmp(aux, to_compare, ft_strlen(aux)) == 0)
		return (free(to_compare), result);
	else
	{
		*flag = 1;
		ft_putstr_fd("Overflow detected\n", 2);
		free(to_compare);
		return (0);
	}
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
