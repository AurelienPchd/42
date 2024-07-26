/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:34:15 by apiochau          #+#    #+#             */
/*   Updated: 2023/11/07 12:34:16 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str1, int val, size_t len)
{
	char	*str;

	str = str1;
	while (len-- > 0)
	{
		*str++ = (unsigned int)val;
	}
	return (str1);
}
