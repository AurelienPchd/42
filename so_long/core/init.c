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

void	init_mlx(t_data *data)
{
	int	x;
	int	y;

	x = ft_strlen_tab(data->map.all);
	y = ft_strlen(*data->map.all);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr || (x * 32 > 2560 && y * 32 > 1440))
		ft_error_1(data, "Env is not correct !");
	data->win_ptr = mlx_new_window(data->mlx_ptr, y * 32, x * 32, "So_long");
	if (!data->win_ptr)
		ft_error_1(data, "Env is not correct !");
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_handler, data);
	mlx_hook(data->win_ptr, DestroyNotify, ButtonPressMask, &on_destroy, data);
}

void	init_map(t_data *data, char *argv, int fd)
{
	char	*mlines;
	char	*map;
	char	*temp;

	fd = open(argv, O_RDONLY);
	if (fd < 1)
	{
		ft_printf("Map does not exist\n");
		exit(0);
	}
	map = ft_calloc(1, 1);
	mlines = get_next_line(fd);
	while (mlines)
	{
		temp = ft_strjoin(map, mlines);
		map = temp;
		free(mlines);
		mlines = get_next_line(fd);
	}
	data->map.all = ft_split(map, '\n');
	data->map.cpall = ft_split(map, '\n');
	data->map.call = ft_split(map, '\n');
	find(data, data->map.all, 'P');
	close(fd);
	free(map);
}

void	init_game(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	if (data->map.all == NULL)
		return ;
	while (data->map.all[++x] != NULL)
	{
		y = -1;
		while (data->map.all[x][++y] != '\0')
		{
			find_and_place(data, x, y);
		}
	}
}

void	init_value(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->col_nbr = 0;
	data->col_reach = 0;
	data->step_nb = 0;
	data->exit_nbr = 0;
	data->exit_reach = 0;
	data->start_nbr = 0;
	data->nbofline = 0;
}
