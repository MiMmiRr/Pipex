/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edervise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:24:06 by edervise          #+#    #+#             */
/*   Updated: 2024/10/02 10:51:51 by edervise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	ft_forker_first(char **av, int *fd, char **envp)
{
	pid_t	pid;

	pid = fork ();
	if (pid == -1)
	{
		perror("Bruh Fork 1 : ");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		close (fd[0]);
		dup2 (fd[1], 1);
		close (fd[1]);
		redirect_input (av[1]);
		transformer_in (envp, av[2]);
	}
}

void	ft_forker_second(char **av, int *fd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror ("Bruh Fork 2 :");
		exit (EXIT_FAILURE);
	}
	if (pid == 0)
	{
		close (fd[1]);
		dup2 (fd[0], 0);
		close (fd[0]);
		redirect_output (av[4]);
		transformer_out (envp, av[3]);
	}
}

void	pipex(char **av, char **envp)
{
	int	fd[2];

	if (pipe(fd) == -1)
	{
		perror("Bruh pipe : ");
		exit(EXIT_FAILURE);
	}
	ft_forker_first (av, fd, envp);
	ft_forker_second (av, fd, envp);
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
}

int	main(int ac, char **av, char **envp)
{
	if (ac != 5)
	{
		perror("Bruh ! Rajoute des args Bro\n");
		return (1);
	}
	pipex(av, envp);
	return (0);
}
