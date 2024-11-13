/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edervise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:43:10 by edervise          #+#    #+#             */
/*   Updated: 2024/10/01 15:09:47 by edervise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	**get_binpath_brut(char **envp)
{
	char	*env_path;
	char	**bin_path;
	int		i;

	env_path = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (!ft_strncmp (envp[i], "PATH=", 5))
		{
			env_path = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (env_path == NULL)
		return (NULL);
	bin_path = ft_split (env_path, ':');
	return (bin_path);
}

char	**get_binpath_clean(char **binpath_brut)
{
	char	**binpath_clean;
	int		i;

	i = 0;
	while (binpath_brut[i] != NULL)
		i++;
	binpath_clean = (char **)malloc ((i + 1) * sizeof(char *));
	if (binpath_clean == NULL)
	{
		perror ("Erreur allocation memoire \n");
		return (NULL);
	}
	i = 0;
	while (binpath_brut[i] != NULL)
	{
		binpath_clean[i] = ft_strjoin (binpath_brut[i], "/");
		i++;
	}
	binpath_clean[i] = NULL;
	return (binpath_clean);
}

char	**pathifier(char *envp[])
{
	char	**binpath_brut;
	char	**binpath_clean;

	binpath_brut = get_binpath_brut (envp);
	binpath_clean = get_binpath_clean (binpath_brut);
	ft_free (binpath_brut);
	return (binpath_clean);
}
