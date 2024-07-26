/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:30:03 by apiochau          #+#    #+#             */
/*   Updated: 2023/11/07 12:30:04 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

void	*ft_calloc(size_t elementCount, size_t elementSize);
void	ft_bzero(void *s, size_t n);
char	*get_next_line(int fd);
char	*ft_read_to_left_str(int fd, char *left_str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);

#endif
