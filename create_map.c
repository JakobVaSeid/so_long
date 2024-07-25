/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:15:54 by jseidere          #+#    #+#             */
/*   Updated: 2024/06/19 17:58:49 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//check params
void	check_params(t_game *so_long)
{
	if (so_long->player != 1)
		ft_error("Invalid map", so_long);
	if (so_long->door != 1)
		ft_error("Invalid map", so_long);
	if (so_long->coins == 0)
		ft_error("Invalid map", so_long);
}

//scan map rows
void	scan_rows(t_game *so_long, char *str, int j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
			ft_error("Invalid map", so_long);
		if (str[i] != 'C' && str[i] != 'P' && str[i] != 'E' \
		&& str[i] != '0' && str[i] != '1' && str[i] != '\n')
			ft_error("Invalid map", so_long);
		if (str[i] == 'C')
			so_long->coins++;
		if (str[i] == 'P')
		{
			so_long->player_x = i;
			so_long->player_y = j;
			so_long->player++;
		}
		if (str[i] == 'E')
			so_long->door++;
		i++;
	}
}

//scan map
void	scan_map(t_game *so_long, char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]) != ft_strlen(str[0]))
			ft_error("Invalid map", so_long);
		scan_rows(so_long, str[i], i);
		i++;
	}
	check_params(so_long);
}

void	place_img_row(t_game *so_long, char *str, int i, int j)
{
	void	*mlx;
	void	*win;
	void	*op_img;
	void	*cl_img;

	mlx = so_long->mlx;
	win = so_long->win;
	op_img = so_long->opendoor_img;
	cl_img = so_long->door_img;
	if (str[i] == '1')
		mlx_put_image_to_window(mlx, win, so_long->wall_img, i * 40, j * 40);
	else if (str[i] == '0')
		mlx_put_image_to_window(mlx, win, so_long->floor_img, i * 40, j * 40);
	else if (str[i] == 'C')
		mlx_put_image_to_window(mlx, win, so_long->coin_img, i * 40, j * 40);
	else if (str[i] == 'E')
	{
		if (so_long->coins == 0)
			mlx_put_image_to_window(mlx, win, op_img, i * 40, j * 40);
		else
			mlx_put_image_to_window(mlx, win, cl_img, i * 40, j * 40);
	}
	else if (str[i] == 'P')
		mlx_put_image_to_window(mlx, win, so_long->player_img, i * 40, j * 40);
}

//place images to screen
void	place_images(t_game *so_long)
{
	int	x;
	int	y;

	y = 0;
	while (y < so_long->rows)
	{
		x = 0;
		while (x < so_long->cols)
		{
			place_img_row(so_long, so_long->map[y], x, y);
			x++;
		}
		y++;
	}
}
