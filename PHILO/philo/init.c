/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:38:07 by ychirouz          #+#    #+#             */
/*   Updated: 2023/07/07 13:21:14 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_mutex(t_dinner *dinner)
{
	int	i;

	i = 0;
	pthread_mutex_init(dinner->message, NULL);
	pthread_mutex_init(dinner->death, NULL);
	pthread_mutex_init(dinner->stop, NULL);
	while (i < dinner->philo_nbr)
		pthread_mutex_init(dinner->forks + i++, NULL);
}

void	destroy_mutex(t_dinner *dinner, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(dinner->death);
	pthread_mutex_destroy(dinner->message);
	pthread_mutex_destroy(dinner->stop);
	while (i < dinner->philo_nbr)
	{
		pthread_mutex_destroy(dinner->forks + i);
		pthread_mutex_destroy(philo[i].eat);
		free(philo[i].eat);
		i++;
	}
	free(philo);
	free(dinner->forks);
	free(dinner->threads);
	free(dinner->death);
	free(dinner->message);
	free(dinner->stop);
}

t_philo	*philo_init(t_dinner *dinner)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = malloc(sizeof(t_philo) * dinner->philo_nbr);
	dinner->stop = malloc(sizeof(pthread_mutex_t));
	dinner->death = malloc(sizeof(pthread_mutex_t));
	dinner->message = malloc(sizeof(pthread_mutex_t));
	while (++i < dinner->philo_nbr)
		each_philo(dinner, philo, i);
	return (philo);
}

void	each_philo(t_dinner *dinner, t_philo *philo, int i)
{
	philo[i].index = i;
	philo[i].l_hand = i;
	philo[i].r_hand = (i + 1) % dinner->philo_nbr;
	philo[i].is_dead = NO;
	philo[i].data = dinner;
	philo[i].eat = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo[i].eat, NULL);
	if (dinner->eat_counter == -1)
		philo[i].eat_counter = -1;
	else
		philo[i].eat_counter = dinner->eat_counter;
}
