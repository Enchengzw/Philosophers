/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_libft2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:51:58 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/14 17:02:25 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

char	*ft_strnew(size_t size)
{
	char	*pointer;

	pointer = (char *)malloc(sizeof(char) * size);
	if (!pointer)
		return (NULL);
	ft_memset(pointer, '\0', size);
	return (pointer);
}

int	ft_number_length(long n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		counter += 1;
	if (n < 0)
		counter += 1;
	while (n != 0)
	{
		n = n / 10;
		counter += 1;
	}
	return (counter);
}

char	*ft_itoa(int ln)
{
	char	*list;
	int		length;

	length = ft_number_length(ln);
	list = ft_strnew(length + 1);
	if (!list)
		return (NULL);
	if (ln < 0)
		list[0] = '-';
	if (ln == 0)
		list[length - 1] = '0';
	list[length] = '\0';
	while (ln != 0)
	{
		if (ln % 10 < 0)
			list[length - 1] = ((ln % 10) * -1) + '0';
		else
			list[length - 1] = (ln % 10) + '0';
		length--;
		ln /= 10;
	}
	return (list);
}

void	ft_putstr_fd(char const *s, int fd)
{
	int	index;

	index = 0;
	while (s[index])
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (us1[index] != us2[index] || !us1[index] || !us2[index])
			return (us1[index] - us2[index]);
		index++;
	}
	return (0);
}
