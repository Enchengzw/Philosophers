/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:58:18 by ezhou             #+#    #+#             */
/*   Updated: 2024/02/15 13:18:23 by ezhou            ###   ########.fr       */
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
	size_t			time_of_last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			initial_time;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*meals_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_t		handler;
	int				quantity;
	int				num_times_to_eat;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meals_lock;
}					t_program;

// PHILOSOPHER FUNCTIONS
int					ft_error_check(int argc, char **argv);
pthread_mutex_t		*ft_initialize(t_params *params, t_philo **philos);
int					ft_initialize_forks(pthread_mutex_t *forks, int quantity);
void				ft_do_something(t_philo *philo, size_t miliseconds);
void				*ft_handler(void *arg);
void				*ft_philo_routine(void *arg);
void				ft_create_handler(t_program *program);

// CLEANING
void				ft_clean_mutexes(pthread_mutex_t *forks, int index);
void				ft_clean_forks(t_philo *philo, t_params *params);
void				ft_free_all(t_program *program, t_params *param);

// NOT LIBFT
int					ft_isdigit(int c);
void				*ft_calloc(size_t count, size_t size);
int					ft_atoi(char *nptr);
size_t				ft_strlen(const char *s);
char				*ft_itoa(int ln);
void				ft_putstr_fd(char const *s, int fd);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_safe_atoi(char *npr, int *flag);
void				ft_putchar_fd(char c, int fd);
void				*ft_memset(void *s, int c, size_t n);

// TIME
int					ft_usleep(size_t milliseconds);
size_t				get_current_time(void);
size_t				ft_current_run_time(size_t old_time);

// ACTIONS
void				ft_is_thinking(t_philo *philo);
int					ft_is_taking_fork_r(t_philo *philo);
void				ft_is_sleeping(t_philo *philo);
void				ft_is_dead(t_philo *philo);
void				ft_is_eating(t_philo *philo);

// VERIFICATION
void				printer(t_philo *philo);

#endif