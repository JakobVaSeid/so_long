/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:50:26 by jseidere          #+#    #+#             */
/*   Updated: 2023/12/14 10:52:15 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(t_game *so_long, int x, int y, char oldchar)
{
	if (x < 0 || x >= so_long->map_columns || y < 0 || y >= so_long->map_rows
		|| so_long->map2[y] == NULL)
		return ;
	if (so_long->map2[y][x] == 'x' || so_long->map2[y][x] == '1' \
	|| so_long->map2[y][x] == 'E')
	{
		if (so_long->map2[y][x] == 'E')
			so_long->map2[y][x] = '1';
		return ;
	}
	so_long->map2[y][x] = 'x';
	fill(so_long, x + 1, y, oldchar);
	fill(so_long, x, y + 1, oldchar);
	fill(so_long, x - 1, y, oldchar);
	fill(so_long, x, y - 1, oldchar);
}

void	flood_fill(t_game *so_long)
{
	char	oldchar;

	oldchar = so_long->map2[so_long->flood.y][so_long->flood.x];
	if (oldchar == 'x' || oldchar == '1')
		return ;
	fill(so_long, so_long->flood.x, so_long->flood.y, oldchar);
}

void	get_map2(t_game *so_long)
{
	int	i;

	so_long->map2 = ft_calloc(sizeof(char *), so_long->map_rows + 1);
	if (!so_long->map2)
		ft_error("Coudln't create map2!", so_long);
	i = 0;
	while (so_long->map[i])
	{
		so_long->map2[i] = ft_strdup(so_long->map[i]);
		if (so_long->map2[i] == NULL)
			free_all(so_long);
		i++;
	}
}

void	check_path(t_game *so_long)
{
	int	i;

	get_map2(so_long);
	i = 0;
	while (so_long->map2[i] != NULL)
		i++;
	flood_fill(so_long);
	i = 0;
	while (so_long->map2[i])
	{
		if (ft_strchr(so_long->map2[i], 'C')
			|| ft_strchr(so_long->map2[i], 'E'))
			ft_error("Invalid path!", so_long);
		i++;
	}
}
