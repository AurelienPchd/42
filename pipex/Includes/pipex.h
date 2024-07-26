/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   All.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:01:21 by apiochau          #+#    #+#             */
/*   Updated: 2024/06/26 16:01:22 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include "../GNL/get_next_line.h"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

void	first_child(t_pipex pipex, char *argv[], char *envp[]);
void	second_child(t_pipex pipex, char *argv[], char *envp[]);
void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);
void	msg_error(char *err);
int		msg(char *err);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
