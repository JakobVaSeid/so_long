/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:51:58 by jseidere          #+#    #+#             */
/*   Updated: 2024/06/19 17:52:20 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//initialize variables
void	init_var(t_game *so_long)
{
	so_long->win = NULL;
	so_long->mlx = NULL;
	so_long->player_img = NULL;
	so_long->wall_img = NULL;
	so_long->floor_img = NULL;
	so_long->coin_img = NULL;
	so_long->door_img = NULL;
	so_long->opendoor_img = NULL;
	so_long->moves = 0;
	so_long->rows = 0;
	so_long->cols = 0;
	so_long->coins = 0;
	so_long->player = 0;
	so_long->door = 0;
	so_long->player_x = 0;
	so_long->player_y = 0;
	so_long->map = NULL;
	so_long->fd = 0;
}

int	xpm_to_img(void *mlx, char *path, void **img)
{
	int	height;
	int	width;

	*img = mlx_xpm_file_to_image(mlx, path, &height, &width);
	if (*img == 0)
		return (0);
	return (1);
}

//initialize images
void	init_img(t_game *so_long)
{
	if (xpm_to_img(so_long->mlx, IMG_PLAYER, &so_long->player_img) == 0)
		ft_error("Failed to load player image", so_long);
	if (xpm_to_img(so_long->mlx, IMG_WALL, &so_long->wall_img) == 0)
		ft_error("Failed to load wall image", so_long);
	if (xpm_to_img(so_long->mlx, IMG_FLOOR, &so_long->floor_img) == 0)
		ft_error("Failed to load floor image", so_long);
	if (xpm_to_img(so_long->mlx, IMG_COIN, &so_long->coin_img) == 0)
		ft_error("Failed to load coin image", so_long);
	if (xpm_to_img(so_long->mlx, IMG_DOOR, &so_long->door_img) == 0)
		ft_error("Failed to load door image", so_long);
	if (xpm_to_img(so_long->mlx, IMG_OPENDO, &so_long->opendoor_img) == 0)
		ft_error("Failed to load open door image", so_long);
}

//init game
void	init_game(t_game *so_long, char **argv)
{
	init_var(so_long);
	init_map(so_long, argv[1]);
	scan_map(so_long, so_long->map);
	so_long->cols = ft_strlen(so_long->map[0]);
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
		ft_error("Mlx failed", so_long);
	init_img(so_long);
}
