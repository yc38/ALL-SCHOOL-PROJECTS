/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:48:11 by ychirouz          #+#    #+#             */
/*   Updated: 2023/07/13 15:19:49 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->next_meal < ft_time())
		{
			philo->data->is_dead = YES;
			pthread_mutex_lock(philo->eat);
			ft_message(5, philo);
			pthread_mutex_unlock(philo->data->stop);
			break ;
		}
	}
	return (NULL);
}

int	ft_check_eat(t_philo *philo)
{
	if ((philo->data->eat_counter != -1) 
		&& (philo->data->current_eat >= philo->data->max_eat))
	{
		philo->data->is_dead = YES;
		pthread_mutex_lock(philo->eat);
		ft_message(6, philo);
		pthread_mutex_unlock(philo->data->stop);
		return (0);
	}
	return (1);
}

void	*ft_routine(void *arg)
{
	t_philo		*philo;
	pthread_t	death;

	philo = arg;
	philo->next_meal = ft_time() + (unsigned int)philo->data->time_to_die;
	pthread_create(&death, NULL, ft_check_death, philo);
	pthread_detach(death);
	while (1)
	{
		if (philo->data->is_dead)
			break ;
		ft_fork(philo);
		ft_eat(philo);
		if (!ft_check_eat(philo))
			break ;
		ft_sleep(philo);
		ft_message(4, philo);
	}
	return (NULL);
}

int	ft_error_put(t_dinner *dinner, char *message, int ret)
{
	if (dinner)
	{
		if (dinner->threads)
			free(dinner->threads);
		if (dinner->forks)
			free(dinner->forks);
	}
	printf("%s\n", message);
	return (ret);
}

int	main(int ac, char **av)
{
	int			i;
	t_dinner	dinner;
	t_philo		*philo;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		if (ft_parsing(av, &dinner))
			return (0);
		philo = philo_init(&dinner);
		dinner.start = ft_time();
		create_mutex(&dinner);
		pthread_mutex_lock(dinner.stop);
		while (i < dinner.philo_nbr)
		{
			pthread_create(dinner.threads + i, NULL, ft_routine, philo + i);
			pthread_detach(dinner.threads[i++]);
			usleep(100);
		}
		pthread_mutex_lock(dinner.stop);
		destroy_mutex(&dinner, philo);
	}
	else
		printf("Error: nbr of av must be == 5 or 6\n");
	system("leaks philo");
	return (0);
}
