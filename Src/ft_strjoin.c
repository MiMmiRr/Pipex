/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edervise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:37:49 by edervise          #+#    #+#             */
/*   Updated: 2024/10/01 14:13:18 by edervise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **docker)
{
	int	i;

	i = 0;
	while (docker[i])
		free(docker[i++]);
	free(docker);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*new_cat;
	size_t		len_s1;
	size_t		len_s2;
	size_t		i;
	size_t		j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_cat = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (new_cat == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		new_cat[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
	{
		new_cat[i + j] = s2[j];
		j++;
	}
	new_cat[i + j] = '\0';
	return (new_cat);
}
