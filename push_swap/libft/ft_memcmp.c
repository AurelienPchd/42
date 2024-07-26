/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:59:38 by apiochau          #+#    #+#             */
/*   Updated: 2023/11/10 12:59:40 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	size_t	position;
	int		delta;

	position = 0;
	while (position++ < len)
	{
		delta = *(unsigned char *)str1++ - *(unsigned char *)str2++;
		if (delta)
			return (delta);
	}
	return (0);
}
