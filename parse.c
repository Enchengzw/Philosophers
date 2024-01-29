/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:57:47 by ezhou             #+#    #+#             */
/*   Updated: 2024/01/29 17:09:22 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_check_number_argument(int argc)
{
	if (argc < 5)
		return (0);
	else if (argc > 6)
		return (0);
	return (1);
}

int	ft_error_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (!ft_check_number_argument(argc))
		return (printf("Number of argument error\n"), 0);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (printf("Non digit argument error\n"), 0);
			j++;
		}
		i++;
	}
	if (ft_atoi(argv[1]) > 200)
		return (printf("More than 200 philosophers error\n"), 0);
	return (1);
}
