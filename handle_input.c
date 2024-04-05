/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:32:51 by jseidere          #+#    #+#             */
/*   Updated: 2023/12/14 10:51:34 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		keypress(int key, t_game *so_long);
void	movement(t_game *so_long, int y, int x);

int	keypress(int key, t_game *so_long)
{
	if (key == 65307)
		free_all(so_long);
	else if (key == LEFT)
		movement(so_long, so_long->playermove.y, so_long->playermove.x - 1);
	else if (key == UP)
		movement(so_long, so_long->playermove.y - 1, so_long->playermove.x);
	else if (key == RIGHT)
		movement(so_long, so_long->playermove.y, so_long->playermove.x + 1);
	else if (key == DOWN)
		movement(so_long, so_long->playermove.y + 1, so_long->playermove.x);
	return (0);
}

void	movement(t_game *so_long, int y, int x)
{
	int	old_x;
	int	old_y;

	old_x = so_long->playermove.x;
	old_y = so_long->playermove.y;
	if (so_long->map[y][x] == DOOR && so_long->map_coins == 0)
	{
		ft_printf("You win!\n");
		free_all(so_long);
	}
	else if (so_long->map[y][x] == FLOOR || so_long->map[y][x] == COIN)
	{
		so_long->map[old_y][old_x] = FLOOR;
		if (so_long->map[y][x] == COIN)
			so_long->map_coins--;
		so_long->playermove.x = x;
		so_long->playermove.y = y;
		so_long->map[y][x] = PLAYER;
		so_long->movements++;
		ft_printf("Movements: %i\n", so_long->movements);
		render_map(so_long);
	}
}
