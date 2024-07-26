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

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft/libft.h"
# include "../libft/printf/include/ft_printf.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define UP 				'5'
# define DOWN 				'2'
# define LEFT 				'3'
# define RIGHT 				'4'

# define WALL 				'1'
# define FLOOR 				'0'
# define COLLECTIBLE		'C'
# define PLAYER				'P'
# define EXIT 				'E'

# define HEIGHT				32
# define WIDTH 				32

# define RESET 				"\r\033[0m"

# define IMG_WALL			"assets/wall.xpm"
# define IMG_FLOOR			"assets/tiles.xpm"
# define IMG_COLLECT		"assets/collec.xpm"
# define IMG_PLAYER 		"assets/rogues.xpm"
# define IMG_PLAYER_UP 		"assets/char_up.xpm"
# define IMG_PLAYER_DOWN	"assets/char_down.xpm"
# define IMG_PLAYER_LEFT	"assets/char_left.xpm"
# define IMG_PLAYER_RIGHT	"assets/char_right.xpm"
# define IMG_EXIT			"assets/door.xpm"
# define IMG_PLAYER_G		"assets/green.xpm"
# define IMG_PLAYER_R		"assets/red.xpm"

# define WIN				"██████████████████████████████████████████████████████████████████\n\
██                                                              ██\n\
██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
██                                                              ██\n\
██████████████████████████████████████████████████████████████████\n\n"

typedef struct s_map
{
	char	**call;
	char	**cpall;
	char	**all;
	int		col;
	int		line;
}			t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		*width;
	int		*height;
	int		col_nbr;
	int		col_reach;
	int		step_nb;
	int		exit_nbr;
	int		exit_reach;
	int		start_nbr;
	char	*p_steps;
	void	*img;
	void	*wall;
	void	*floor;
	void	*collect;
	void	*player;
	void	*exit;
	void	*up;
	void	*down;
	void	*left;
	void	*right;
	int		nbofline;
	t_map	map;
}			t_data;

int			is_rec(t_data *data);
int			on_destroy(t_data *data);
int			is_up(t_data *data);
int			key_handler(int keycode, t_data *data);
int			is_down(t_data *data);
int			is_left(t_data *data);
int			is_right(t_data *data);
void		init_map(t_data *data, char *argv, int fd);
void		find_and_place(t_data *data, int x, int y);
void		init_texture(t_data *data);
void		bg_render(t_data *data, void *conv, int line, int col);
void		init_mlx(t_data *data);
void		init_game(t_data *data);
void		player_move_up(t_data *data, int i);
void		free_all(char **t);
void		player_move_down(t_data *data, int i);
void		player_move_left(t_data *data, int i);
void		player_move_right(t_data *data, int i);
void		find(t_data *data, char **str, char c);
void		border_checker(t_data *data);
void		is_ber(char *av);
void		ft_error_1(t_data *data, char *str);
void		enough_rec(t_data *data);
void		init_value(t_data *data);
void		floodfill(t_data *data, int x, int y);
void		full_ff(t_data *data);
void		check_map_comp(t_data *data);
void		ft_win(t_data *data, char *str);

#endif