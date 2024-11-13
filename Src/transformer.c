/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edervise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:00:37 by edervise          #+#    #+#             */
/*   Updated: 2024/10/02 10:48:04 by edervise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
char	*commander(char *cmd, char **bin_path, char **cmd_args)
{
	char *cmd_path;
	int	i;
	
	i = 0;
	if (!ft_strncmp(cmd, "/", 1) || !ft_strncmp(cmd, "./", 2))
	{
		if (access (cmd, F_OK | X_OK) == 0)
			return (cmd);
	}
	while (bin_path[i])
	{	
		cmd_path = ft_strjoin (bin_path[i], cmd_args[0]);
		if (!cmd_path)
		{
			perror ("Bruh strjoin failed");
			ft_free (bin_path);
			ft_free (cmd_args);
		}
		if (access (cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

void	transformer_in(char **envp, char *cmd)
{
	char	**bin_path;
	char	**cmd_args;
	char	*cmd_path;

	bin_path = pathifier (envp);
	cmd_args = ft_split (cmd, ' ');
	cmd_path = commander (cmd, bin_path, cmd_args);
			
	if (execve (cmd_path, cmd_args, envp) == -1)
	{
		perror ("Bruh execve child1 : ");
		free (cmd_path);
		ft_free (bin_path);
		ft_free (cmd_args);
		exit (EXIT_FAILURE);
	}
	free (cmd_path);
	ft_free (bin_path);
	ft_free (cmd_args);
}
*/

char	*commander(char **bin_path, char **cmd_args, char *cmd)
{
	char	*cmd_path;
	int		i;

	if (access(cmd,F_OK) == 0)
		return (cmd);
	i = 0;
	while (bin_path[i])
	{
		cmd_path = ft_strjoin (bin_path[i], cmd_args[0]);
		if (!cmd_path)
		{
			perror ("Bruh strjoin failed");
			ft_free (bin_path);
			ft_free (cmd_args);
		}
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (cmd);
}

void	transformer_in(char **envp, char *cmd)
{
	char	**bin_path;
	char	**cmd_args;
	char	*cmd_path;

	bin_path = pathifier (envp);
	cmd_args = ft_split (cmd, ' ');
	cmd_path = commander (bin_path, cmd_args, cmd);
	if (execve (cmd_path, cmd_args, envp) == -1)
	{
		perror ("Bruh execve child1 : ");
		ft_free (bin_path);
		ft_free (cmd_args);
		exit (EXIT_FAILURE);
	}
	free (cmd_path);
	ft_free (bin_path);
	ft_free (cmd_args);
}

void	transformer_out(char **envp, char *cmd)
{
	char	**bin_path;
	char	**cmd_args;
	char	*cmd_path;

	bin_path = pathifier (envp);
	cmd_args = ft_split (cmd, ' ');
	cmd_path = commander (bin_path, cmd_args, cmd);
	if (execve (cmd_path, cmd_args, envp) == -1)
	{
		perror ("Bruh execve child2 : ");
		ft_free (bin_path);
		ft_free (cmd_args);
		exit (EXIT_FAILURE);
	}
	free (cmd_path);
	ft_free (bin_path);
	ft_free (cmd_args);
}
