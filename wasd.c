/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:35:41 by bhocsak           #+#    #+#             */
/*   Updated: 2024/09/13 19:35:43 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moving_w(t_mlx *game)
{
	if ((game->map[game->p_y - 1][game->p_x] == 'E' && !game->c_num))
	{
		ft_printf("YOU WON\n\n");
		exit_clean_way_won(game);
	}
	if (game->map[game->p_y - 1][game->p_x] == '1' ||
		(game->map[game->p_y - 1][game->p_x] == 'E' && game->c_num))
		return (0);
	if (game->map[game->p_y - 1][game->p_x] == 'C')
		game->c_num--;
	game->map[game->p_y][game->p_x] = '0';
	game->map[game->p_y - 1][game->p_x] = 'P';
	game->p_y--;
	fill_up_window(game);
	game->steps++;
	ft_printf("Movements: %d\n\n", game->steps);
	return (1);
}

int	moving_a(t_mlx *game)
{
	if ((game->map[game->p_y][game->p_x - 1] == 'E' && !game->c_num))
	{
		ft_printf("YOU WON\n\n");
		exit_clean_way_won(game);
	}
	if (game->map[game->p_y][game->p_x - 1] == '1' ||
		(game->map[game->p_y][game->p_x - 1] == 'E' && game->c_num))
		return (0);
	if (game->map[game->p_y][game->p_x - 1] == 'C')
		game->c_num--;
	game->map[game->p_y][game->p_x] = '0';
	game->map[game->p_y][game->p_x - 1] = 'P';
	game->p_x--;
	fill_up_window(game);
	game->steps++;
	ft_printf("Movements: %d\n\n", game->steps);
	return (1);
}

int	moving_s(t_mlx *game)
{
	if ((game->map[game->p_y + 1][game->p_x] == 'E' && !game->c_num))
	{
		ft_printf("YOU WON\n\n");
		exit_clean_way_won(game);
	}
	if (game->map[game->p_y + 1][game->p_x] == '1' ||
		(game->map[game->p_y + 1][game->p_x] == 'E' && game->c_num))
		return (0);
	if (game->map[game->p_y + 1][game->p_x] == 'C')
		game->c_num--;
	game->map[game->p_y][game->p_x] = '0';
	game->map[game->p_y + 1][game->p_x] = 'P';
	game->p_y++;
	fill_up_window(game);
	game->steps++;
	ft_printf("Movements: %d\n\n", game->steps);
	return (1);
}

int	moving_d(t_mlx *game)
{
	if ((game->map[game->p_y][game->p_x + 1] == 'E' && !game->c_num))
	{
		ft_printf("YOU WON\n\n");
		exit_clean_way_won(game);
	}
	if (game->map[game->p_y][game->p_x + 1] == '1' ||
		(game->map[game->p_y][game->p_x + 1] == 'E' && game->c_num))
		return (0);
	if (game->map[game->p_y][game->p_x + 1] == 'C')
		game->c_num--;
	game->map[game->p_y][game->p_x] = '0';
	game->map[game->p_y][game->p_x + 1] = 'P';
	game->p_x++;
	fill_up_window(game);
	game->steps++;
	ft_printf("Movements: %d\n\n", game->steps);
	return (1);
}
