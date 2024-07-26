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

void	floodfill(t_data *data, int x, int y)
{
	if (data->map.cpall[x][y] == '1')
		return ;
	else if (data->map.cpall[x][y] == EXIT)
		data->exit_reach++;
	data->map.cpall[x][y] = WALL;
	if (data->map.cpall[x][y + 1] != WALL)
		floodfill(data, x, y + 1);
	if (data->map.cpall[x][y - 1] != WALL)
		floodfill(data, x, y - 1);
	if (data->map.cpall[x + 1][y] != WALL)
		floodfill(data, x + 1, y);
	if (data->map.cpall[x - 1][y] != WALL)
		floodfill(data, x - 1, y);
}

void	floodfill_c(t_data *data, int x, int y)
{
	if (data->map.call[x][y] == '1')
		return ;
	else if (data->map.call[x][y] == COLLECTIBLE)
		data->col_reach++;
	data->map.call[x][y] = WALL;
	if (data->map.call[x][y + 1] != WALL && data->map.call[x][y + 1] != EXIT)
		floodfill_c(data, x, y + 1);
	if (data->map.call[x][y - 1] != WALL && data->map.call[x][y - 1] != EXIT)
		floodfill_c(data, x, y - 1);
	if (data->map.call[x + 1][y] != WALL && data->map.call[x + 1][y] != EXIT)
		floodfill_c(data, x + 1, y);
	if (data->map.call[x - 1][y] != WALL && data->map.call[x - 1][y] != EXIT)
		floodfill_c(data, x - 1, y);
}

void	full_ff(t_data *data)
{
	floodfill(data, data->map.col, data->map.line);
	floodfill_c(data, data->map.col, data->map.line);
	if (data->exit_nbr != data->exit_reach || data->col_nbr != data->col_reach)
		ft_error_1(data, "Map is not valid");
}
