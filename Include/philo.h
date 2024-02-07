/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:58:18 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/07 17:58:30 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define RED_TEXT "\x1b[31m"
# define BLUE_TEXT "\x1b[34m"
# define GREEN_TEXT "\x1b[32m"
# define DARK_GREEN_TEXT "\033[0;32m"
# define RESET_TEXT "\x1b[0m"
# define ORANGE_TEXT "\x1b[38;2;255;165;0m"

typedef struct s_params
{
	int				quantity;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_limit;
	size_t			time;
}					t_params;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				initial_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;

// PHILOSOPHER FUNCTIONS
int					ft_error_check(int argc, char **argv);
void				ft_initialize(t_params *params, t_philo *philos);
int					ft_initialize_forks(pthread_mutex_t *forks, int quantity);
void				ft_do_something(t_philo *philo, size_t miliseconds);

// CLEANING
void				ft_clean_mutexes(pthread_mutex_t *forks, int index);

// NOT LIBFT
int					ft_isdigit(int c);
void				*ft_calloc(size_t count, size_t size);
long				ft_atoi(char *nptr);
size_t				ft_strlen(const char *s);

// TIME
int					ft_usleep(size_t milliseconds);
size_t				get_current_time(void);
size_t				ft_current_run_time(size_t old_time);

// ACTIONS
void				ft_is_thinking(t_philo *philo);
void				ft_is_taking_fork(t_philo *philo);
void				ft_is_sleeping(t_philo *philo);
void				ft_is_dead(t_philo *philo);
void				ft_is_eating(t_philo *philo);

// VERIFICATION
void				printer(t_philo *philo);

#endif