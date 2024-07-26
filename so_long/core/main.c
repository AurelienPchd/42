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

static void	start_game(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_handler, data);
	mlx_loop(data->mlx_ptr);
}

static void	verif_map(t_data *data)
{
	enough_rec(data);
	is_rec(data);
	border_checker(data);
	check_map_comp(data);
	full_ff(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		is_ber(argv[1]);
		init_value(&data);
		init_map(&data, argv[1], 0);
		verif_map(&data);
		init_mlx(&data);
		init_texture(&data);
		init_game(&data);
		start_game(&data);
	}
	return (0);
}
