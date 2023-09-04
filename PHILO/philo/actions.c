/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:46:03 by ychirouz          #+#    #+#             */
/*   Updated: 2023/07/07 13:20:08 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->l_hand]);
	ft_message(1, philo);
	pthread_mutex_lock(&philo->data->forks[philo->r_hand]);
	ft_message(1, philo);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->eat);
	ft_message(2, philo);
	if (philo->data->eat_counter != -1)
		philo->data->current_eat++;
	philo->eating_time = ft_time();
	philo->next_meal = philo->eating_time + 
		(unsigned int)philo->data->time_to_die;
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->l_hand]);
	pthread_mutex_unlock(&philo->data->forks[philo->r_hand]);
	pthread_mutex_unlock(philo->eat);
}

void	ft_sleep(t_philo *philo)
{
	usleep(10);
	ft_message(3, philo);
	usleep(philo->data->time_to_sleep * 1000);
}
