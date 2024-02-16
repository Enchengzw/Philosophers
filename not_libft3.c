/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_libft3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:02:34 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/16 12:36:18 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		((unsigned char *)s)[index] = c;
		index++;
	}
	return (s);
}
