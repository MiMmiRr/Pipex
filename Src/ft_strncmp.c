/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edervise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:26:27 by edervise          #+#    #+#             */
/*   Updated: 2024/09/21 13:46:30 by edervise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(char *str1, char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] == str2[i]) && str1[i] != '\0' && str2[i] != '\0')
	{
		i++;
		if (i >= n)
			return (0);
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
