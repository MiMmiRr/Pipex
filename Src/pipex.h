/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edervise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:49:16 by edervise          #+#    #+#             */
/*   Updated: 2024/10/02 11:00:44 by edervise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>

		/** LIBFT  **/
int		ft_strlen(char *s);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char *s, size_t start, size_t len);
int		ft_strncmp(char *str1, char *str2, size_t n);
char	*strnstr(char *haystack, char *needle, size_t n);

		/** PIPEX **/

void	pipex(char **av, char **envp);

	/* PIPE */
void	transformer_in(char **envp, char *cmd);

void	transformer_out(char **envp, char *cmd);
char	**pathifier(char **envp);

char	**get_binpath_brut(char **envp);
char	**get_binpath_clean(char **envp);

	/* REDIRECTION */
void	redirect_input(char *av_entry);
void	redirect_output(char *av_entry);

void	ft_free(char **docker);

#endif
