/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edervise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:46:31 by edervise          #+#    #+#             */
/*   Updated: 2024/10/01 14:32:19 by edervise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dstsize == 0 || src == NULL || dst == NULL)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < (dstsize -1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

static int	ft_countok(char *s, char c)
{
	size_t	tok_count;
	size_t	inside_tok;

	tok_count = 0;
	while (*s)
	{
		inside_tok = 0;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			if (!inside_tok)
			{
				inside_tok = 1;
				tok_count++;
			}
			s++;
		}
	}
	return (tok_count);
}

static int	guide_malloc_docker(char **docker, int pos, size_t size)
{
	int	i;

	i = 0;
	docker[pos] = malloc(size);
	if (docker[pos] == NULL)
	{
		while (i < pos)
			free(docker[i++]);
		return (1);
	}
	return (0);
}

static size_t	cpy_itok(char **docker, char *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			++len;
			++s;
		}
		if (len)
		{
			if (guide_malloc_docker(docker, i, len + 1))
				return (1);
			ft_strlcpy(docker[i], s - len, len + 1);
			i++;
		}
		docker[i] = NULL;
	}
	return (0);
}

char	**ft_split(char *s, char c)
{
	char	**docker;
	size_t	token_count;

	if (s == NULL)
		return (NULL);
	token_count = ft_countok(s, c);
	if (*s == '\0' || token_count == 0)
	{
		docker = malloc(1 * sizeof(char *));
		if (docker == NULL)
			return (NULL);
		docker[0] = NULL;
		return (docker);
	}
	docker = malloc((token_count + 1) * sizeof(char *));
	if (docker == NULL)
		return (NULL);
	if (cpy_itok(docker, s, c))
		return (NULL);
	return (docker);
}
