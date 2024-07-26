/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:38:17 by apiochau          #+#    #+#             */
/*   Updated: 2023/11/09 12:38:19 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t lestrlen)
{
	size_t	i;

	i = 0;
	if (lestrlen == 0)
		return (0);
	while (str1[i] == str2[i] && i < lestrlen - 1 && str1[i] && str2[i])
		i++;
	return (*(unsigned char *)(str1 + i) - *(unsigned char *)(str2 + i));
}
