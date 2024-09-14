/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:55:22 by bhocsak           #+#    #+#             */
/*   Updated: 2024/09/13 17:55:24 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(t_mlx *game, int x, int y)
{
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr,
			game->window, game->collect, x * SIZE, y * SIZE);
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr,
			game->window, game->exit, x * SIZE, y * SIZE);
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr,
			game->window, game->empty, x * SIZE, y * SIZE);
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr,
			game->window, game->player, x * SIZE, y * SIZE);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr,
			game->window, game->wall, x * SIZE, y * SIZE);
}

void	images_converter(t_mlx *game)
{
	convert(game, &game->collect, "images/c_50x50.xpm");
	convert(game, &game->exit, "images/e_50x50.xpm");
	convert(game, &game->empty, "images/0_50x50.xpm");
	convert(game, &game->player, "images/p_50x50.xpm");
	convert(game, &game->wall, "images/1_50x50.xpm");
	if (!game->collect || !game->exit || !game->empty
		|| !game->player || !game->wall)
	{
		write(2, "Error, character(s) could not be opened\n", 40);
		exit_clean_way(game);
	}
}

void	convert(t_mlx *game, void **image_ptr, char *xpm_file_path)
{
	int		width;
	int		height;

	(void)game;
	(void)xpm_file_path;
	width = SIZE;
	height = SIZE;
	*image_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			xpm_file_path, &width, &height);
}

int	do_mlx(struct s_map map)
{
	t_mlx	game;

	game.map = map.map;
	game.width = map.x_max + 1;
	game.heigth = map.y_max + 1;
	game.steps = 0;
	game.c_num = map.c;
	game.p_x = its_x(map, 'P');
	game.p_y = its_y(map, 'P');
	game.mlx_ptr = NULL;
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (write(2, "Error\n", 6), 0);
	game.window = NULL;
	game.window = mlx_new_window(game.mlx_ptr,
			game.width * SIZE, game.heigth * SIZE, "so_long");
	if (!game.window)
		return (mlx_destroy_display(game.mlx_ptr),
			free(game.mlx_ptr), write(2, "Error\n", 6), 0);
	images_converter(&game);
	fill_up_window(&game);
	mlx_hook(game.window, 17, 0, handle_click_x, &game);
	mlx_key_hook(game.window, handle_keyboard, &game);
	mlx_loop(game.mlx_ptr);
	return (1);
}
