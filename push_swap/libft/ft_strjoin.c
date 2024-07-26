/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:15:38 by apiochau          #+#    #+#             */
/*   Updated: 2023/11/13 16:15:38 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*str;

	if (!str1 || !str2)
		return (0);
	s1_len = ft_strlen((char *)str1);
	s2_len = ft_strlen((char *)str2);
	i = 0;
	j = -1;
	str = malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!str)
		return (NULL);
	while (i < s1_len)
	{
		str[i] = str1[i];
		i++;
	}
	while (++j < s2_len)
		str[i + j] = str2[j];
	str[i + j] = '\0';
	return (str);
}
