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

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char	*str2;

	str2 = (unsigned char *)str;
	while (len-- > 0)
	{
		if (*str2 == (unsigned char)c)
			return (str2);
		str2++;
	}
	return (NULL);
}
