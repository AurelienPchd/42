/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:59:29 by apiochau          #+#    #+#             */
/*   Updated: 2023/11/13 13:59:32 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	border_checker(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map.all[x][y] != '\0')
	{
		if (data->map.all[x][y] != '1')
			ft_error_1(data, "Map  is not unclosed");
		y++;
	}
	y--;
	while (++x <= data->nbofline)
		if (data->map.all[x][y] != '1')
			ft_error_1(data, "Map  is not unclosed");
	x--;
	while (--y >= 0)
		if (data->map.all[x][y] != '1')
			ft_error_1(data, "Map  is not unclosed");
	while (--x >= 0)
		if (data->map.all[x][0] != '1')
			ft_error_1(data, "Map  is not unclosed");
}

void	is_ber(char *av)
{
	int	x;

	x = ft_strlen(av) - 1;
	if (av[x--] != 'r')
	{
		ft_printf("\033[1m\033[31m Extension is not ok\n");
		exit(0);
	}
	if (av[x--] != 'e')
	{
		ft_printf("\033[1m\033[31m Extension is not ok\n");
		exit(0);
	}
	if (av[x--] != 'b')
	{
		ft_printf("\033[1m\033[31m Extension is not ok\n");
		exit(0);
	}
	if (av[x] != '.')
	{
		ft_printf("\033[1m\033[31m Extension is not ok\n");
		exit(0);
	}
	x--;
}

int	is_rec(t_data *data)
{
	size_t	x;
	int		y;
	size_t	len;

	x = 0;
	y = 0;
	len = ft_strlen(data->map.all[0]);
	while (data->map.all[++y])
	{
		if (ft_strlen(data->map.all[y]) != len)
			ft_error_1(data, "Map is not rectangular");
	}
	data->nbofline = y - 1;
	return (0);
}

void	enough_rec(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map.all[y])
	{
		x = 0;
		while (data->map.all[y][x])
		{
			if (data->map.all[y][x] == 'E')
				data->exit_nbr += 1;
			if (data->map.all[y][x] == 'P')
				data->start_nbr += 1;
			if (data->map.all[y][x] == 'C')
				data->col_nbr += 1;
			x++;
		}
		y++;
	}
	if (data->col_nbr < 1 || data->exit_nbr != 1 || data->start_nbr != 1)
		ft_error_1(data, "Map is not correct");
}

void	check_map_comp(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.all[x])
	{
		y = 0;
		while (data->map.all[x][y])
		{
			if (data->map.all[x][y] != WALL && data->map.all[x][y] != PLAYER
				&& data->map.all[x][y] != EXIT
				&& data->map.all[x][y] != COLLECTIBLE
				&& data->map.all[x][y] != FLOOR)
				ft_error_1(data, "Map is not correct");
			y++;
		}
		x++;
	}
}
