/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edervise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:51:15 by edervise          #+#    #+#             */
/*   Updated: 2024/10/01 15:27:03 by edervise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_input(char *av_entry)
{
	int	fd_open;

	fd_open = open (av_entry, O_RDONLY);
	if (fd_open == -1)
	{
		perror("Bruh ouverture file : ");
		exit(1);
	}
	dup2 (fd_open, 0);
	close (fd_open);
	return ;
}

void	redirect_output(char *av_out)
{
	int	fd_output;

	fd_output = open (av_out, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_output == -1)
	{
		perror ("Bruh ouverture file :");
		exit (EXIT_FAILURE);
	}
	dup2 (fd_output, 1);
	close (fd_output);
}
