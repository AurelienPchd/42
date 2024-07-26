/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:06:56 by apiochau          #+#    #+#             */
/*   Updated: 2023/09/12 12:06:59 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_sub_atoi(char *str, int *i, int *m)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n' || \
	str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		*i = *i + 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*m = *m + 1;
		*i = *i + 1;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	retour;
	int	m;

	i = 0;
	retour = 0;
	m = 0;
	ft_sub_atoi((char *)str, &i, &m);
	while (str[i] >= '0' && str[i] <= '9')
	{
		retour = retour * 10 + (str[i] - '0');
		i++;
	}
	m = m % 2;
	if (m != 0)
		m = -1;
	else
		m = 1;
	return (retour * m);
}
