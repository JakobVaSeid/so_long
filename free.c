/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:25:39 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/02 12:32:45 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

//destroy all images
void	free_images(t_game *so_long)
{
	if (so_long->player_img)
		mlx_destroy_image(so_long->mlx, so_long->player_img);
	if (so_long->wall_img)
		mlx_destroy_image(so_long->mlx, so_long->wall_img);
	if (so_long->floor_img)
		mlx_destroy_image(so_long->mlx, so_long->floor_img);
	if (so_long->coin_img)
		mlx_destroy_image(so_long->mlx, so_long->coin_img);
	if (so_long->opendoor_img)
		mlx_destroy_image(so_long->mlx, so_long->opendoor_img);
	if (so_long->door_img)
		mlx_destroy_image(so_long->mlx, so_long->door_img);
}

void	free_map(t_game *so_long)
{
	int	i;

	i = 0;
	if (so_long->map)
	{
		while (i < so_long->rows)
		{
			free(so_long->map[i]);
			i++;
		}
		free(so_long->map);
	}
	else
		return ;
}

//
int	free_success(t_game *so_long)
{
	free_all(so_long);
	exit(0);
}

//free everything
void	free_all(t_game *so_long)
{
	free_images(so_long);
	free_map(so_long);
	if (so_long->win && so_long->mlx)
		mlx_destroy_window(so_long->mlx, so_long->win);
	if (so_long->mlx)
		mlx_destroy_display(so_long->mlx);
	if (so_long->mlx)
		free(so_long->mlx);
	if (so_long->fd)
		close(so_long->fd);
}

//Error Message
void	ft_error(char *str, t_game *so_long)
{
	write(2, "Error: ", 7);
	while (*str)
		write(2, str++, 1);
	write(2, "\n", 1);
	free_all(so_long);
	exit(1);
}
