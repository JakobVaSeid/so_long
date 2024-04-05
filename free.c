/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:12:54 by jseidere          #+#    #+#             */
/*   Updated: 2023/12/14 17:44:39 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_game *so_long);
void	free_map(t_game *so_long);

int	free_all(t_game *so_long)
{
	destroy_images(so_long);
	free_map2(so_long);
	free_map(so_long);
	if (so_long->mlx_ptr && so_long->win)
		mlx_destroy_window(so_long->mlx_ptr, so_long->win);
	if (so_long->mlx_ptr)
		mlx_destroy_display(so_long->mlx_ptr);
	free(so_long->mlx_ptr);
	exit(0);
	return (0);
}

void	destroy_images(t_game *so_long)
{
	if (so_long->wall.xpm_ptr)
		mlx_destroy_image(so_long->mlx_ptr, so_long->wall.xpm_ptr);
	if (so_long->door.xpm_ptr)
		mlx_destroy_image(so_long->mlx_ptr, so_long->door.xpm_ptr);
	if (so_long->floor.xpm_ptr)
		mlx_destroy_image(so_long->mlx_ptr, so_long->floor.xpm_ptr);
	if (so_long->player.xpm_ptr)
		mlx_destroy_image(so_long->mlx_ptr, so_long->player.xpm_ptr);
	if (so_long->coin.xpm_ptr)
		mlx_destroy_image(so_long->mlx_ptr, so_long->coin.xpm_ptr);
	if (so_long->open_door.xpm_ptr)
		mlx_destroy_image(so_long->mlx_ptr, so_long->open_door.xpm_ptr);
}

void	free_map(t_game *so_long)
{
	int	i;

	i = 0;
	if (!so_long->map)
		return ;
	while (so_long->map[i])
	{
		free(so_long->map[i]);
		i++;
	}
	free(so_long->map);
}

void	free_map2(t_game *so_long)
{
	int	i;

	i = 0;
	if (!so_long->map2)
		return ;
	while (so_long->map2[i])
	{
		free(so_long->map2[i]);
		i++;
	}
	free(so_long->map2);
}

int	ft_error(char *message, t_game *so_long)
{
	ft_printf("Error:\n%s", message);
	free_all(so_long);
	exit (EXIT_FAILURE);
}
