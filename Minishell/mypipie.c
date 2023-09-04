/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mypipie.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:08:18 by ychirouz          #+#    #+#             */
/*   Updated: 2023/06/13 15:48:46 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void	write_in_fd(char *str, char *filename)
{
	int fd;
	int	dup;
	
	fd = open(filename, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("fd");
		exit(0);
	}
	if (dup2(fd, fd) == -1)
	{
		perror("dup2");
		exit(0);
	}
	if (write(fd, str, strlen(str)) == -1)
	{
		perror("writefd");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

int main(int ac, char **av)
{
//	char	*str;
//	char	*filename;
//	char	*cat = av[1];
//	char	*dir = av[2];

	//	str = av[3];
	//	filename = av[4];
		write_in_fd("coucou\n", "filename");
	return (0);
}
