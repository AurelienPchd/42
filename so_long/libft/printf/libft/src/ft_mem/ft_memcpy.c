/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:06:59 by apiochau          #+#    #+#             */
/*   Updated: 2023/11/07 14:07:01 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*str;
	const char	*source = src;

	if (dest == 0 && src == 0)
		return (0);
	str = dest;
	while (n-- > 0)
	{
		*str++ = *source++;
	}
	return (dest);
}
