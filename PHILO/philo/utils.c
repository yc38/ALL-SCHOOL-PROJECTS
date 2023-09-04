/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:30:43 by ychirouz          #+#    #+#             */
/*   Updated: 2023/07/07 13:39:13 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(t_dinner *dinner, char *str, int n)
{
	if (dinner)
	{
		if (dinner->threads)
			free(dinner->threads);
		if (dinner->forks)
			free(dinner->forks);
	}
	printf("%s\n", str);
	return (n);
}

unsigned int	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_message(int w, t_philo *philo)
{
	unsigned int	time;

	pthread_mutex_lock(philo->data->message);
	time = ft_time() - philo->data->start;
	if (w == 1)
		printf("%u %d has taken a fork\n", time, philo->index + 1);
	else if (w == 2)
		printf("%u %d is eating\n", time, philo->index + 1);
	else if (w == 3)
		printf("%u %d is sleeping\n", time, philo->index + 1);
	else if (w == 4)
		printf("%u %d is thinking\n", time, philo->index + 1);
	else if (w == 5)
		printf("%u %d died\n", time, philo->index + 1);
	else if (w == 6)
		printf("Dinner is finish\n");
	if (w != 5 && w != 6)
		pthread_mutex_unlock(philo->data->message);
}
