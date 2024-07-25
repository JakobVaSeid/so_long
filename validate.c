/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:04:22 by jseidere          #+#    #+#             */
/*   Updated: 2024/06/20 15:42:05 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//check if next move is possible
int	can_move(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == 'E')
		return (0);
	else if (map[y][x] == '0' || map[y][x] == 'C')
		return (1);
	return (0);
}

int	all_reachable(t_game *so_long, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->rows)
	{
		j = 0;
		while (map && map[i] && map[i][j])
		{
			if (map[i][j] == 'E')
			{
				if (map[i][j + 1] != 'X' && (j > 0 && map[i][j - 1] != 'X') \
				&& map[i + 1][j] != 'X' && (i > 0 && map[i - 1][j] != 'X'))
					return (1);
			}
			if (map[i][j] == 'P' || map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//check if path is valid
void	check_path(t_game *so_long, char **map_tmp, int y, int x)
{
	map_tmp[y][x] = 'X';
	if (!can_move(map_tmp, y - 1, x) && !can_move(map_tmp, y + 1, x) \
		&& !can_move(map_tmp, y, x - 1) && !can_move(map_tmp, y, x + 1))
		return ;
	if (can_move(map_tmp, y - 1, x))
		check_path(so_long, map_tmp, y - 1, x);
	if (can_move(map_tmp, y, x - 1))
		check_path(so_long, map_tmp, y, x - 1);
	if (can_move(map_tmp, y + 1, x))
		check_path(so_long, map_tmp, y + 1, x);
	if (can_move(map_tmp, y, x + 1))
		check_path(so_long, map_tmp, y, x + 1);
}

//check if map is valid
void	valid_map(t_game *so_long)
{
	char	**map_tmp;

	map_tmp = malloc(sizeof(char *) * so_long->rows);
	if (!map_tmp)
		ft_error("Malloc failed", so_long);
	so_long->flood_fill_x = so_long->player_x;
	so_long->flood_fill_y = so_long->player_y;
	copy_map(so_long->map, map_tmp, so_long->rows);
	check_path(so_long, map_tmp, so_long->flood_fill_y, so_long->flood_fill_x);
	if (all_reachable(so_long, map_tmp))
	{
		free_map_temp(map_tmp, so_long->rows);
		ft_error("Invalid map", so_long);
	}
	free_map_temp(map_tmp, so_long->rows);
}
