/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:45:21 by apiochau          #+#    #+#             */
/*   Updated: 2023/11/10 13:45:29 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub_str, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (len == 0 && str == 0)
		return (NULL);
	if (!*sub_str)
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == sub_str[j] && i + j < len)
		{
			if (!sub_str[j + 1])
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
