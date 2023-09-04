/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:00:03 by ychirouz          #+#    #+#             */
/*   Updated: 2023/06/06 18:00:36 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct t_addenv
{
	char	*str;
	struct t_addenv  *next;
}	t_addenv;

void	ft_export(char *str, char **env)
{
	int	i;

	i = 0;
	while (env[i + 1])
		printf("%s\n", env[i++]);
	printf("%s\n", str);
	printf("%s\n", env[i]);
}

int main(int ac, char **av, char **env)
{
	int	i = 0;
	t_addenv allenv;
	allenv.str = av[1];
	while (i < ac)
	{
		allenv.str = av[i];
		allenv = allenv->next
		i++;
	}
	ft_export(allenv.str, env);
	return (0);
}
	


