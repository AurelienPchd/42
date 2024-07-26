/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   All.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:01:21 by apiochau          #+#    #+#             */
/*   Updated: 2024/06/26 16:01:22 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	msg_pipe(char *arg)
{
	write(2, "Command not found\n", ft_strlen("Command not found\n"));
	write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
}

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}
