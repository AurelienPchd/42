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

void	bg_render(t_data *data, void *conv, int line, int col)
{
	if (conv == NULL)
		return ;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, conv, col * 32, line
		* 32);
}

void	init_texture(t_data *data)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	data->wall = NULL;
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, IMG_WALL, &x, &y);
	data->floor = NULL;
	data->floor = mlx_xpm_file_to_image(data->mlx_ptr, IMG_FLOOR, &x, &y);
	data->exit = NULL;
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, IMG_EXIT, &x, &y);
	data->player = NULL;
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, IMG_PLAYER, &x, &y);
	data->collect = NULL;
	data->collect = mlx_xpm_file_to_image(data->mlx_ptr, IMG_COLLECT, &x, &y);
	if (!data->wall || !data->player || !data->floor || !data->exit
		|| !data->collect)
		ft_error_1(data, "Assets not valid");
}

void	find_and_place(t_data *data, int x, int y)
{
	if (data->map.all[x][y] == WALL)
		bg_render(data, data->wall, x, y);
	if (data->map.all[x][y] == FLOOR)
		bg_render(data, data->floor, x, y);
	if (data->map.all[x][y] == PLAYER)
		bg_render(data, data->player, x, y);
	if (data->map.all[x][y] == COLLECTIBLE)
		bg_render(data, data->collect, x, y);
	if (data->map.all[x][y] == EXIT)
		bg_render(data, data->exit, x, y);
}
