/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:57:56 by apiochau          #+#    #+#             */
/*   Updated: 2023/11/09 14:57:57 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*str2;

	str2 = (char *)str;
	while (*str2 != (char)c)
	{
		if (*str2 == '\0')
		{
			return (NULL);
		}
		str2++;
	}
	return (str2);
}
