/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:43:01 by ychirouz          #+#    #+#             */
/*   Updated: 2023/07/07 13:23:25 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_set_rest(t_dinner *dinner, int n, int i)
{
	if (i == 3)
	{
		if (n < 60)
			return (ft_error(dinner,
					"Error: time_to_eat(av[3]) min = 60ms", 1));
		dinner->time_to_eat = n;
	}
	else if (i == 4)
	{
		if (n < 60)
			return (ft_error(dinner,
					"Error: THE time_to_sleep(av[4]) min = 60 ms", 1));
		dinner->time_to_sleep = n;
	}
	else
		ft_check_last(dinner, n, i);
	return (0);
}

int	ft_check_last(t_dinner *dinner, int n, int i)
{
	if (i == 5)
	{
		if (n == 0)
		{
			dinner->eat_counter = -1;
			dinner->current_eat = -1;
			dinner->max_eat = -1;
		}
		else
		{
			dinner->eat_counter = n;
			dinner->current_eat = 0;
			dinner->max_eat = n * dinner->philo_nbr;
		}
	}
	return (0);
}

int	init_dinner(t_dinner *dinner, int num, int i)
{
	if (i == 1)
	{
		if (num == 0)
			return (ft_error(NULL, "Error: Nbr philosopher min = 1", 1));
		dinner->philo_nbr = num;
		dinner->threads = malloc(sizeof(pthread_t) * num);
		dinner->forks = malloc(sizeof(pthread_mutex_t) * num);
	}
	else if (i == 2)
	{
		if (num < 60)
			return (ft_error(dinner, 
					"Error: time_to_die(argv2) min = 60", 1));
		dinner->time_to_die = num;
	}
	else
		ft_set_rest(dinner, num, i);
	return (0);
}

int	ft_get_number(char *av)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (av[i])
	{
		if (av[i] >= '0' && av[i] <= '9')
			num = num * 10 + (av[i] - '0');
		else
			return (ft_error(NULL, "Error: only positive numbers", -1));
		i++;
	}
	return (num);
}

int	ft_parsing(char **av, t_dinner *dinner)
{
	int	i;
	int	n;

	i = 1;
	while (av[i])
	{
		n = ft_get_number(av[i]);
		if (n == -1)
			return (1);
		if (init_dinner(dinner, n, i))
			return (1);
		i++;
	}
	if (i == 5)
	{
		dinner->eat_counter = -1;
		dinner->current_eat = -1;
		dinner->max_eat = -1;
	}
	dinner->is_dead = NO;
	return (0);
}
