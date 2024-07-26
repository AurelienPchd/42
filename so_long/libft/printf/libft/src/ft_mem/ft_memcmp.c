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

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	size_t	position;
	int		delta;

	position = 0;
	while (position++ < size)
	{
		delta = *(unsigned char *)pointer1++ - *(unsigned char *)pointer2++;
		if (delta)
			return (delta);
	}
	return (0);
}
