/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylyly.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:52:42 by ychirouz          #+#    #+#             */
/*   Updated: 2023/06/13 15:52:51 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void store_ls_result(char *filename)
{
    int fd;
    int dup_ret;

    fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    dup_ret = dup2(fd, STDOUT_FILENO);
    if (dup_ret == -1)
    {
        perror("dup2");
        exit(EXIT_FAILURE);
    }

    if (execlp("ls", "ls", NULL) == -1)
    {
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    close(fd);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    store_ls_result(argv[1]);

    return EXIT_SUCCESS;
}

