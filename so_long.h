/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:27:39 by jseidere          #+#    #+#             */
/*   Updated: 2023/12/14 17:44:31 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include "get_next_line.h"

# define UP     119
# define DOWN   115
# define LEFT   97
# define RIGHT  100
# define ESC    65307

# define IMG_HEIGHT			40
# define IMG_WIDTH			40

# define WALL				'1'
# define FLOOR 				'0'
# define COIN	  			'C'
# define PLAYER				'P'
# define DOOR 		 		'E'

# define WALL_XPM			"textures/wall.xpm"
# define FLOOR_XPM			"textures/floor.xpm"
# define COIN_XPM			"textures/coin.xpm"
# define DOOR_XPM			"textures/door.xpm"
# define PLAYER_XPM			"textures/player.xpm"
# define OPEN_DOOR_XPM		"textures/fwechsle.xpm"

typedef struct s_img
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_img;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win;
	t_img	wall;
	t_img	door;
	t_img	open_door;
	t_img	floor;
	t_img	player;
	t_img	coin;
	t_point	playermove;
	t_point	flood;
	int		map_columns;
	int		map_rows;
	int		map_coins;
	int		map_exit;
	int		map_player;
	int		movements;
	char	**map;
	char	**map2;
}	t_game;

void	init_map(t_game *game, char *argv);
int		free_all(t_game *so_long);
void	free_map2(t_game *so_long);
int		ft_error(char *message, t_game *so_long);

void	check_map(t_game *so_long);
void	check_column(t_game *so_long);
void	check_row(t_game *so_long);
void	count_parameter(t_game *so_long);
void	verify_map_parameters(t_game *so_long);

void	init_sprites(t_game *so_long);
int		render_map(t_game *so_long);
t_img	load_xpm(void *mlx, char *filename, t_game *so_long);
void	place_img(t_game *so_long, int y, int x);
void	movement(t_game *so_long, int y, int x);
int		keypress(int key, t_game *so_long);
void	check_path(t_game *so_long);

#endif