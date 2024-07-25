/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:57:48 by jseidere          #+#    #+#             */
/*   Updated: 2024/06/20 19:05:31 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//make a move
void	move_right(t_game *so_long)
{
	if (so_long->map[so_long->player_y][so_long->player_x + 1] == '1')
		return ;
	else if (so_long->map[so_long->player_y][so_long->player_x + 1] == '0'
		|| so_long->map[so_long->player_y][so_long->player_x + 1] == 'C')
	{
		if (so_long->map[so_long->player_y][so_long->player_x + 1] == 'C')
			so_long->coins--;
		so_long->map[so_long->player_y][so_long->player_x + 1] = 'P';
		so_long->map[so_long->player_y][so_long->player_x] = '0';
		so_long->player_x++;
		so_long->moves++;
		ft_printf("Moves: %d\n", so_long->moves);
	}
	else if (so_long->map[so_long->player_y][so_long->player_x + 1] == 'E' \
		&& so_long->coins == 0)
	{
		so_long->player_x++;
		so_long->moves++;
		ft_printf("Moves: %d\n", so_long->moves);
		ft_printf("You win!\n");
		free_success(so_long);
	}
}

//move left
void	move_left(t_game *so_long)
{
	if (so_long->map[so_long->player_y][so_long->player_x - 1] == '1')
		return ;
	else if (so_long->map[so_long->player_y][so_long->player_x - 1] == '0'
		|| so_long->map[so_long->player_y][so_long->player_x - 1] == 'C')
	{
		if (so_long->map[so_long->player_y][so_long->player_x - 1] == 'C')
			so_long->coins--;
		so_long->map[so_long->player_y][so_long->player_x - 1] = 'P';
		so_long->map[so_long->player_y][so_long->player_x] = '0';
		so_long->player_x--;
		so_long->moves++;
		ft_printf("Moves: %d\n", so_long->moves);
	}
	else if (so_long->map[so_long->player_y][so_long->player_x - 1] == 'E' \
		&& so_long->coins == 0)
	{
		so_long->player_x--;
		so_long->moves++;
		ft_printf("Moves: %d\n", so_long->moves);
		ft_printf("You win!\n");
		free_success(so_long);
	}
}

//move up
void	move_up(t_game *so_long)
{
	if (so_long->map[so_long->player_y - 1][so_long->player_x] == '1')
		return ;
	else if (so_long->map[so_long->player_y - 1][so_long->player_x] == '0'
		|| so_long->map[so_long->player_y - 1][so_long->player_x] == 'C')
	{
		if (so_long->map[so_long->player_y - 1][so_long->player_x] == 'C')
			so_long->coins--;
		so_long->map[so_long->player_y - 1][so_long->player_x] = 'P';
		so_long->map[so_long->player_y][so_long->player_x] = '0';
		so_long->player_y--;
		so_long->moves++;
		ft_printf("Moves: %d\n", so_long->moves);
	}
	else if (so_long->map[so_long->player_y - 1][so_long->player_x] == 'E' \
		&& so_long->coins == 0)
	{
		so_long->player_y--;
		so_long->moves++;
		ft_printf("Moves: %d\n", so_long->moves);
		ft_printf("You win!\n");
		free_success(so_long);
	}
}

//move down
void	move_down(t_game *so_long)
{
	if (so_long->map[so_long->player_y + 1][so_long->player_x] == '1')
		return ;
	else if (so_long->map[so_long->player_y + 1][so_long->player_x] == '0'
		|| so_long->map[so_long->player_y + 1][so_long->player_x] == 'C')
	{
		if (so_long->map[so_long->player_y + 1][so_long->player_x] == 'C')
			so_long->coins--;
		so_long->map[so_long->player_y + 1][so_long->player_x] = 'P';
		so_long->map[so_long->player_y][so_long->player_x] = '0';
		so_long->player_y++;
		so_long->moves++;
		ft_printf("Moves: %d\n", so_long->moves);
	}
	else if (so_long->map[so_long->player_y + 1][so_long->player_x] == 'E' \
		&& so_long->coins == 0)
	{
		so_long->player_y++;
		so_long->moves++;
		ft_printf("Moves: %d\n", so_long->moves);
		ft_printf("You win!\n");
		free_success(so_long);
	}
}
