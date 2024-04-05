/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:23:06 by jseidere          #+#    #+#             */
/*   Updated: 2023/12/14 10:53:16 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_game *so_long)
{
	check_column(so_long);
	check_row(so_long);
	count_parameter(so_long);
	so_long->flood.x = so_long->playermove.x;
	so_long->flood.y = so_long->playermove.y;
	verify_map_parameters(so_long);
	check_path(so_long);
}

void	count_parameter(t_game *so_long)
{
	int	y;
	int	x;

	y = 0;
	while (y < so_long->map_rows)
	{
		x = 0;
		while (x < so_long->map_columns)
		{
			if (!ft_strchr("01CPE", so_long->map[y][x]))
				ft_error("Wrong parameter in map!", so_long);
			else if (so_long->map[y][x] == COIN)
				so_long->map_coins++;
			else if (so_long->map[y][x] == PLAYER)
			{
				so_long->map_player++;
				so_long->playermove.y = y;
				so_long->playermove.x = x;
			}
			else if (so_long->map[y][x] == DOOR)
				so_long->map_exit++;
			x++;
		}
		y++;
	}
}

void	check_row(t_game *so_long)
{
	int	y;

	y = 0;
	while (y < so_long->map_rows)
	{
		if ((so_long->map[y][0] != WALL)
		|| (so_long->map[y][so_long->map_columns - 1] != WALL)
		|| (ft_strlen(so_long->map[y]) != so_long->map_columns))
			ft_error("Amount of rows is wrong!", so_long);
		y++;
	}
}

void	check_column(t_game *so_long)
{
	int	x;

	x = 0;
	while (x < so_long->map_columns)
	{
		if ((so_long->map[0][x] != WALL)
		|| (so_long->map[so_long->map_rows - 1][x] != WALL))
			ft_error("Amount of columns is wrong!", so_long);
		x++;
	}
}

void	verify_map_parameters(t_game *so_long)
{
	if (so_long->map_coins == 0)
		ft_error("Not enough coins!", so_long);
	else if (so_long->map_player != 1)
		ft_error("Amount of Player is wrong!", so_long);
	else if (so_long->map_exit != 1)
		ft_error("Amount of exit is wrong!", so_long);
}
