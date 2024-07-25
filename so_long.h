/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:04:30 by jseidere          #+#    #+#             */
/*   Updated: 2024/06/20 16:23:49 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <get_next_line/get_next_line.h>
# include <ft_printf/ft_printf.h>
# include <ft_printf/libft/libft.h>

# define UP         119
# define DOWN       115
# define LEFT       97
# define RIGHT      100
# define SPACE      32
# define ESC        65307

# define IMG_WALL    "textures/wall.xpm"
# define IMG_FLOOR   "textures/floor.xpm"
# define IMG_COIN    "textures/coin.xpm"
# define IMG_PLAYER  "textures/player.xpm"
# define IMG_JMP     "textures/jump.xpm"
# define IMG_DOOR    "textures/door.xpm"
# define IMG_OPENDO  "textures/fwechsle.xpm"

typedef struct s_game
{
	char	**map;
	char	**map_temp;
	int		*mlx;
	int		*win;
	int		fd;
	int		rows;
	int		cols;
	int		coins;
	int		door;
	int		player;
	int		player_x;
	int		player_y;
	int		moves;
	int		flood_fill_x;
	int		flood_fill_y;
	void	*player_img;
	void	*jmp_img;
	void	*wall_img;
	void	*floor_img;
	void	*coin_img;
	void	*door_img;
	void	*opendoor_img;
}				t_game;

////////////////////////////////////////////
/////////////////FUNCTIONS/////////////////
//////////////////////////////////////////

//so_long.c
void	copy_map(char **map, char **map_temp, int rows);
void	free_map_temp(char **map_temp, int rows);

//free.c
void	free_images(t_game *so_long);
void	free_map(t_game *so_long);
void	ft_error(char *str, t_game *so_long);
void	free_all(t_game *so_long);
int		free_success(t_game *so_long);

//create_map.c
void	place_images(t_game *so_long);
void	scan_rows(t_game *so_long, char *str, int i);
void	scan_map(t_game *so_long, char **str);

//read_map.c
int		check_for_newline(char *str);
void	double_free(char *s1, char *s2, int fd, t_game *so_long);
void	single_free(char *s1, t_game *so_long);
char	*get_map_temp(t_game *so_long, char *map_temp, int fd);
void	init_map(t_game *so_long, char *map_temp);

//init_game.c
void	init_var(t_game *so_long);
void	init_img(t_game *so_long);
void	init_game(t_game *so_long, char **argv);

//validate.c
void	valid_map(t_game *so_long);
void	check_path(t_game *so_long, char **map_tmp, int y, int x);

//movement.c
void	move_left(t_game *so_long);
void	move_right(t_game *so_long);
void	move_up(t_game *so_long);
void	move_down(t_game *so_long);

#endif