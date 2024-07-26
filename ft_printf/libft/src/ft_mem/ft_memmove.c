/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:34:49 by apiochau          #+#    #+#             */
/*   Updated: 2023/11/07 14:34:51 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destination;
	const char	*source;

	if (dest == 0 && src == 0)
		return (0);
	destination = dest;
	source = src;
	if (destination < source)
	{
		while (n-- > 0)
			*destination++ = *source++;
	}
	else
	{
		destination += n - 1;
		source += n - 1;
		while (n-- > 0)
			*destination-- = *source--;
	}
	return (dest);
}
