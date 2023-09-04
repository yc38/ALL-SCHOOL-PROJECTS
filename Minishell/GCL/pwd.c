/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:59:14 by ychirouz          #+#    #+#             */
/*   Updated: 2023/06/06 13:18:04 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_pwd()
{
	char	path[4096];

	if (getcwd(path, sizeof(path)))
		printf("%s\n", path);
	else
		printf("shit\n");
}

int main()
{
	ft_pwd();
	return (0);
}
