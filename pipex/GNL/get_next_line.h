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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
int		find_nl(char *str);
char	*str_join(char *s1, char *s2);
char	*get_line(char *str);
char	*trim_rem(char *str);
int		some_error(char *str);

#endif
