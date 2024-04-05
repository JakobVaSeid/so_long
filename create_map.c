/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:46:05 by jseidere          #+#    #+#             */
/*   Updated: 2023/12/06 14:27:24 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_img(t_game *so_long, int y, int x);
t_img	load_xpm(void *mlx, char *filename, t_game *so_long);
void	ft_print_movements(t_game *so_long);

void	init_sprites(t_game *so_long)
{
	void	*mlx;

	mlx = so_long->mlx_ptr;
	so_long->wall = load_xpm(mlx, WALL_XPM, so_long);
	so_long->floor = load_xpm(mlx, FLOOR_XPM, so_long);
	so_long->door = load_xpm(mlx, DOOR_XPM, so_long);
	so_long->open_door = load_xpm(mlx, OPEN_DOOR_XPM, so_long);
	so_long->coin = load_xpm(mlx, COIN_XPM, so_long);
	so_long->player = load_xpm(mlx, PLAYER_XPM, so_long);
}

int	render_map(t_game *so_long)
{
	int	x;
	int	y;

	y = 0;
	while (y < so_long->map_rows)
	{
		x = 0;
		while (x < so_long->map_columns)
		{
			place_img(so_long, y, x);
			x++;
		}
		y++;
	}
	return (0);
}

void	render_img(t_game *so_long, t_img sprite, int line, int column)
{
	mlx_put_image_to_window (so_long->mlx_ptr, so_long->win, \
	sprite.xpm_ptr, column * sprite.x, line * sprite.y);
}

void	place_img(t_game *so_long, int y, int x)
{
	if (so_long->map[y][x] == WALL)
		render_img(so_long, so_long->wall, y, x);
	else if (so_long->map[y][x] == COIN)
		render_img(so_long, so_long->coin, y, x);
	else if (so_long->map[y][x] == FLOOR)
		render_img(so_long, so_long->floor, y, x);
	else if (so_long->map[y][x] == DOOR)
	{
		if (so_long->map_coins > 0)
			render_img(so_long, so_long->door, y, x);
		else if (so_long->map_coins == 0)
			render_img(so_long, so_long->open_door, y, x);
	}
	else if (so_long->map[y][x] == PLAYER)
		render_img(so_long, so_long->player, y, x);
}

t_img	load_xpm(void *mlx, char *filename, t_game *so_long)
{
	t_img	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, filename, &sprite.y, &sprite.x);
	if (sprite.xpm_ptr == NULL)
	{
		ft_printf("Couldn't find sprite");
		free_all(so_long);
		exit(EXIT_FAILURE);
	}
	return (sprite);
}
