/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:52:58 by caigner           #+#    #+#             */
/*   Updated: 2023/12/18 10:56:34 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_game *so_long)
{
	so_long->mlx_ptr = NULL;
	so_long->win = NULL;
	so_long->map_coins = 0;
	so_long->map_exit = 0;
	so_long->map_player = 0;
	so_long->map_columns = 0;
	so_long->map_rows = 0;
	so_long->movements = 0;
	so_long->wall.xpm_ptr = NULL;
	so_long->door.xpm_ptr = NULL;
	so_long->open_door.xpm_ptr = NULL;
	so_long->floor.xpm_ptr = NULL;
	so_long->player.xpm_ptr = NULL;
	so_long->coin.xpm_ptr = NULL;
}

void	init_mlx(t_game *so_long)
{
	so_long->mlx_ptr = mlx_init();
	if (so_long->mlx_ptr == NULL)
		free_all(so_long);
	so_long->win = mlx_new_window(so_long->mlx_ptr, \
	so_long->map_columns * IMG_WIDTH, \
	so_long->map_rows * IMG_HEIGHT, "so_long");
	if (so_long->win == NULL)
		free_all(so_long);
}

int	main(int argc, char **argv )
{
	t_game	so_long;

	if (argc == 2)
	{
		so_long.map = NULL;
		so_long.map2 = NULL;
		init_vars(&so_long);
		init_map(&so_long, argv[1]);
		so_long.map_columns = ft_strlen(so_long.map[0]);
		check_map(&so_long);
		init_mlx(&so_long);
		init_sprites(&so_long);
		render_map(&so_long);
		mlx_hook(so_long.win, 17, 0, free_all, &so_long);
		mlx_hook(so_long.win, 2, 1, keypress, &so_long);
		mlx_loop(so_long.mlx_ptr);
		free_all(&so_long);
	}
	return (0);
}
