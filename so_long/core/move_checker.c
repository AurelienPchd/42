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

int	is_up(t_data *data)
{
	if (data->map.all[data->map.col - 1][data->map.line] == '1')
		return (0);
	if (data->map.all[data->map.col - 1][data->map.line] == 'C')
		data->col_nbr -= 1;
	if (data->map.all[data->map.col - 1][data->map.line] == 'E'
		&& data->col_nbr == 0)
		ft_win(data, WIN);
	if (data->map.all[data->map.col - 1][data->map.line] == 'E'
		&& data->col_nbr != 0)
		return (0);
	data->step_nb++;
	ft_printf("Movement :%d\r\033[0m", data->step_nb);
	return (1);
}

int	is_down(t_data *data)
{
	if (data->map.all[data->map.col + 1][data->map.line] == '1')
		return (0);
	if (data->map.all[data->map.col + 1][data->map.line] == 'C')
		data->col_nbr -= 1;
	if (data->map.all[data->map.col + 1][data->map.line] == 'E'
		&& data->col_nbr == 0)
		ft_win(data, WIN);
	if (data->map.all[data->map.col + 1][data->map.line] == 'E'
		&& data->col_nbr != 0)
		return (0);
	data->step_nb++;
	ft_printf("Movement :%d\r\033[0m", data->step_nb);
	return (1);
}

int	is_left(t_data *data)
{
	if (data->map.all[data->map.col][data->map.line - 1] == '1')
		return (0);
	if (data->map.all[data->map.col][data->map.line - 1] == 'C')
		data->col_nbr -= 1;
	if (data->map.all[data->map.col][data->map.line - 1] == 'E'
		&& data->col_nbr == 0)
		ft_win(data, WIN);
	if (data->map.all[data->map.col][data->map.line - 1] == 'E'
		&& data->col_nbr != 0)
		return (0);
	data->step_nb++;
	ft_printf("Movement :%d\r\033[0m", data->step_nb);
	return (1);
}

int	is_right(t_data *data)
{
	if (data->map.all[data->map.col][data->map.line + 1] == '1')
		return (0);
	if (data->map.all[data->map.col][data->map.line + 1] == 'C')
		data->col_nbr -= 1;
	if (data->map.all[data->map.col][data->map.line + 1] == 'E'
		&& data->col_nbr == 0)
		ft_win(data, WIN);
	if (data->map.all[data->map.col][data->map.line + 1] == 'E'
		&& data->col_nbr != 0)
		return (0);
	data->step_nb++;
	ft_printf("Movement :%d\r\033[0m", data->step_nb);
	return (1);
}
