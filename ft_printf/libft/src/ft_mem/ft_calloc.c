/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:56:01 by apiochau          #+#    #+#             */
/*   Updated: 2023/11/13 12:56:02 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size && (nmemb > SIZE_MAX / size))
		return (NULL);
	tab = (void *)malloc(nmemb * size);
	if (tab == NULL)
		return (NULL);
	ft_memset((unsigned char *)tab, 0, nmemb * size);
	return (tab);
}
