/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:27:42 by ychirouz          #+#    #+#             */
/*   Updated: 2023/06/06 12:07:50 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	changehemp(char *str, char *str2)
{
	int	i;

	i = 0;
//	free(str);
	str = malloc(strlen(str2) * sizeof(char *));
	while (str2[i])
	{
		str[i] = str2[i];
		i++;
	}
	str[i] = 0x00;
}

char	*copydex(char *var, int j)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(((strlen(var) - j) * sizeof(char *)));
	j++;
	while (var[j])
	{
		str[i] = var[j];
		i++;
		j++;
	}
		return (str);
}
		
char *enviro(char *str, char **envav)
{
	int	i;
	int	j;
	int	k;
	int	index;
	char	*nwstr;

	nwstr = malloc(strlen(str) * sizeof(char));
	i = 0;
	
	while (envav[i])
	{
		j = 0;
		k = 0;
		if (envav[i][j] == str[k])
		{
		while (envav[i][j] == str[k])
		{
			if (envav[i][j + 1] == '=')
			{
				return (strcpy(str, copydex(envav[i], j + 1)));
			
			}
			j++;
			k++;
		}
		}
		i++;
	}
	return ("nada");
}

int main(int ac, char **av, char **env)
{
	int i = 0;
	char  *str = av[1];
//	strcpy(str, enviro(str, env));
	printf("%s\n", enviro(str, env));
	return (0);
}
