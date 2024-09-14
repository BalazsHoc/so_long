/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keyhandler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:54:59 by bhocsak           #+#    #+#             */
/*   Updated: 2024/09/13 17:55:01 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_click_x(t_mlx *game)
{
	write(1, "You quit the program\n", 21);
	return (exit_clean_way_won(game));
}

int	handle_keyboard(int key, t_mlx *game)
{
	if (key == XK_Escape)
	{
		write(1, "You quit the program\n", 21);
		exit_clean_way_won(game);
	}
	(void)game;
	if (key == XK_w)
		moving_w(game);
	if (key == XK_a)
		moving_a(game);
	if (key == XK_s)
		moving_s(game);
	if (key == XK_d)
		moving_d(game);
	return (0);
}

void	fill_up_window(t_mlx *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->heigth)
	{
		while (j < game->width)
		{
			put_images(game, j, i);
			j++;
		}
		j = 0;
		i++;
	}
}
