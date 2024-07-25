/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:02:57 by jseidere          #+#    #+#             */
/*   Updated: 2024/06/20 15:56:34 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

//free map_temp
void	free_map_temp(char **map_temp, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map_temp[i]);
		i++;
	}
	free(map_temp);
}

//copy map to map_temp
void	copy_map(char **map, char **map_temp, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		map_temp[i] = ft_strdup(map[i]);
		if (!map_temp[i])
		{
			free_map_temp(map_temp, i);
			return ;
		}
		i++;
	}
}

//function for pressing a key
int	key_hook(int keycode, t_game *so_long)
{
	if (keycode == 65307)
		free_success(so_long);
	if (keycode == RIGHT)
		move_right(so_long);
	if (keycode == LEFT)
		move_left(so_long);
	if (keycode == DOWN)
		move_down(so_long);
	if (keycode == UP)
		move_up(so_long);
	place_images(so_long);
	return (0);
}

//check if window size is valid
int	check_valid_window_size(t_game *so_long)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(so_long->mlx, &screen_width, &screen_height);
	if (so_long->cols * 40 > screen_width \
	|| so_long->rows * 40 > screen_height - 60)
	{
		ft_error("Invalid window size", so_long);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	so_long;

	if (argc == 2)
	{
		init_game(&so_long, argv);
		if (check_valid_window_size(&so_long) == 1)
			ft_error("Window failed", &so_long);
		valid_map(&so_long);
		so_long.win = mlx_new_window(so_long.mlx, so_long.cols * 40, \
			so_long.rows * 40, "so_long");
		if (!so_long.win)
			ft_error("Window failed", &so_long);
		place_images(&so_long);
		mlx_hook(so_long.win, 2, 1, key_hook, &so_long);
		mlx_hook(so_long.win, 17, 0, free_success, &so_long);
		mlx_loop(so_long.mlx);
	}
	else
		write(2, "Error: Invalid number of arguments\n", 36);
	return (0);
}
