/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:01:21 by apiochau          #+#    #+#             */
/*   Updated: 2023/11/09 16:01:22 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_char(char const *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (!s1)
		return (0);
	j = ft_strlen((char *)s1);
	if (!set)
		ft_strdup((char *)s1);
	while (s1[i] && check_char(set, s1[i]))
		i++;
	while (check_char(set, s1[j - 1]) && j - 1 > i)
		j--;
	str = malloc(sizeof(char) * (j - i + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1 + i, j - i + 1);
	return (str);
}
