/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Alls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/17/05 12:06:56 by apiochau          #+#    #+#             */
/*   Updated: 2024/17/05 14:06:59 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	int	y;

	y = i;
	while (argv[++y])
	{
		if (ft_atoi(argv[y]) == num)
			return (1);
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	verif_args(int argc, char **argv)
{
	int		i;
	int		y;
	long	tmp;
	char	**args;

	i = 0;
	y = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		y = 1;
	}
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		verif_args_2(y, i, args, tmp);
		i++;
	}
	if (argc == 2)
		ft_free(args);
}

void	verif_args_2(int y, int i, char **args, long tmp)
{
	if (!ft_isnum(args[i]))
	{
		if (y == 1)
			ft_error_1("Error", args);
		else
			ft_error("Error");
	}
	if (ft_contains(tmp, args, i))
	{
		if (y == 1)
			ft_error_1("Error", args);
		else
			ft_error("Error");
	}
	if (tmp < -2147483648 || tmp > 2147483647 || ft_strlen(args[i]) > 11)
	{
		if (y == 1)
			ft_error_1("Error", args);
		else
			ft_error("Error");
	}
}
