/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cattest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:59:32 by ychirouz          #+#    #+#             */
/*   Updated: 2023/06/12 17:07:06 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid = fork();

    if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
    }
	else if (pid == 0)
	{
        // Processus fils
        // Rediriger la sortie standard vers le fichier "file1"
		freopen("file1", "w", stdout);
        // Exécuter la commande "echo"
		execl("/bin/echo", "echo", "hello654", NULL);
        // Si execl retourne, cela signifie qu'il y a eu une erreur
		perror("execl");
		exit(EXIT_FAILURE);
    }
	else
	{
        // Processus parent
		int status;
		waitpid(pid, &status, 0);
        	if (WIFEXITED(status))
				printf("Command executed successfully.\n");
			else
				printf("Command failed to execute.\n");
    }
    return (0);
}

