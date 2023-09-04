/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:48:13 by ychirouz          #+#    #+#             */
/*   Updated: 2023/07/13 15:19:56 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define YES 1
# define NO 0

typedef struct s_dinner
{
	pthread_t			*threads;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*message;
	pthread_mutex_t		*death;
	pthread_mutex_t		*stop;
	unsigned int		start;
	int					philo_nbr;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					eat_counter;
	int					max_eat;
	int					is_dead;
	int					current_eat;
}	t_dinner;

typedef struct s_philo
{
	pthread_mutex_t	*eat;
	t_dinner		*data;
	unsigned int	eating_time;
	unsigned int	next_meal;
	int				index;
	int				r_hand;
	int				l_hand;
	int				is_dead;
	int				eat_counter;
}	t_philo;

void			ft_fork(t_philo *philo);
void			ft_eat(t_philo *philo);
void			ft_sleep(t_philo *philo);
void			create_mutex(t_dinner *dinner);
void			destroy_mutex(t_dinner *dinner, t_philo *philo);
void			each_philo(t_dinner *dinner, t_philo *philo, int i);
t_philo			*philo_init(t_dinner *dinner);
int				init_dinner(t_dinner *dinner, int num, int i);
int				ft_get_number(char *av);
int				ft_parsing(char **av, t_dinner *dinner);
int				ft_set_rest(t_dinner *dinner, int num, int i);
int				ft_check_last(t_dinner *dinner, int n, int i);
int				ft_error(t_dinner *dinner, char *str, int n);
unsigned int	ft_time(void);
void			ft_message(int w, t_philo *philo);

#endif
