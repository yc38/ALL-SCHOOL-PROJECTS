/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:19:48 by ychirouz          #+#    #+#             */
/*   Updated: 2023/06/06 15:01:49 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
typedef struct s_env
{
	char	*var;
	char	*val;

	struct s_env	*next;
}	t_env;

char	*copy_b_equal(char *str)
{
	int		i;
	char	*nwstr;

	i = 0;
	while (str[i] != '=')
		i++;
	nwstr = malloc(sizeof(char *) * i + 1);
	i = 0;
	while (str[i] != '=')
	{
		nwstr[i] = str[i];
		i++;
	}
	nwstr[i] = 0x00;
	return (nwstr);
}

char	*copy_a_equal(char *str)
{
	int		i;
	int		j;
	char	*nwstr;

	i = 0;
	j = 0;
	while (str[i] != '=')
		i++;
	i++;
	nwstr = malloc(sizeof(char *) * (strlen(str) - i) + 1);
	while (str[i])
	{
		nwstr[j] = str[i];
		i++;
		j++;
	}
	nwstr[j] = 0x00;
	return (nwstr);
}

void	crea_env_fil(char **env, t_env *allenv)
{
	t_env	*start;
	int		i;
	int	j;

	start = allenv;
	j = 0;
	i = 0;
	while (env[i])
	{
		allenv->var = copy_b_equal(env[i]);
		allenv->val = copy_a_equal(env[i]);
		allenv = ft_lstnew(all;
		i++;
	}
	allenv->next = NULL;
}	

void	ft_env(t_env *env)
{
	while (env->next)
	{
		printf("%s=%s\n", env->var, env->val);
		env = env->next;
	}
}

int main(int ac, char **av, char **env) 
{
	t_env	nez;

	crea_env_fil(env, &nez);
    return 1;
}

