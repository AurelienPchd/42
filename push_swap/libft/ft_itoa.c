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

static size_t	get_digits(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str_num;
	size_t		digits;
	long int	num;

	num = n;
	digits = get_digits(n);
	if (n < 0)
		num *= -1;
	(str_num = (char *)malloc(sizeof(char) * (digits + 1)));
	if (!str_num)
		return (NULL);
	str_num[digits] = 0;
	while (digits--)
	{
		str_num[digits] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		str_num[0] = '-';
	return (str_num);
}
