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

void	player_move_up(t_data *data, int move)
{
	if (move == UP && is_up(data))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor,
			data->map.line * HEIGHT, data->map.col * WIDTH);
		data->map.all[--data->map.col][data->map.line] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player,
			data->map.line * 32, data->map.col * 32);
	}
}

void	player_move_down(t_data *data, int move)
{
	if (move == DOWN && is_down(data))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor,
			data->map.line * 32, data->map.col * 32);
		data->map.all[++data->map.col][data->map.line] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player,
			data->map.line * 32, data->map.col * 32);
	}
}

void	player_move_left(t_data *data, int move)
{
	if (move == LEFT && is_left(data))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor,
			data->map.line * 32, data->map.col * 32);
		data->map.all[data->map.col][--data->map.line] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player,
			data->map.line * 32, data->map.col * 32);
	}
}

void	player_move_right(t_data *data, int move)
{
	if (move == RIGHT && is_right(data))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor,
			data->map.line * 32, data->map.col * 32);
		data->map.all[data->map.col][++data->map.line] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player,
			data->map.line * 32, data->map.col * 32);
	}
}
