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

int	key_handler(int keycode, t_data *data)
{
	int	x;

	x = 0;
	if (keycode == XK_Up || keycode == 'w')
		player_move_up(data, UP);
	else if (keycode == XK_s || keycode == XK_Down)
		player_move_down(data, DOWN);
	else if (keycode == XK_Left || keycode == XK_a)
		player_move_left(data, LEFT);
	else if (keycode == XK_Right || keycode == XK_d)
		player_move_right(data, RIGHT);
	else if (keycode == 'g')
	{
		mlx_destroy_image(data->mlx_ptr, data->player);
		data->player = mlx_xpm_file_to_image(data->mlx_ptr, IMG_PLAYER_G, &x,
				&x);
	}
	if (keycode == XK_Escape)
		ft_error_1(data, "Give up, looser!");
	return (0);
}

int	on_destroy(t_data *data)
{
	if (data->floor)
		mlx_destroy_image(data->mlx_ptr, data->floor);
	if (data->wall)
		mlx_destroy_image(data->mlx_ptr, data->wall);
	if (data->player)
		mlx_destroy_image(data->mlx_ptr, data->player);
	if (data->exit)
		mlx_destroy_image(data->mlx_ptr, data->exit);
	if (data->collect)
		mlx_destroy_image(data->mlx_ptr, data->collect);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_all(data->map.all);
	exit(EXIT_SUCCESS);
}

void	find(t_data *data, char **str, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (str[x])
	{
		y = 0;
		while (str[x][y])
		{
			if (str[x][y] == c)
				break ;
			y++;
		}
		if (str[x][y] == c)
			break ;
		x++;
	}
	data->map.col = x;
	data->map.line = y;
}

void	ft_error_1(t_data *data, char *str)
{
	ft_printf("\033[1m\033[31m%s\n", str);
	if (data->map.cpall && data->map.all)
	{
		free_all(data->map.cpall);
		free_all(data->map.call);
	}
	if (data->mlx_ptr)
		on_destroy(data);
	free_all(data->map.all);
	exit(0);
}

void	ft_win(t_data *data, char *str)
{
	ft_printf("\033[1m\033[32m%s\n", str);
	if (data->map.cpall && data->map.all)
	{
		free_all(data->map.cpall);
		free_all(data->map.call);
	}
	if (data->mlx_ptr)
		on_destroy(data);
	free_all(data->map.all);
	exit(0);
}
