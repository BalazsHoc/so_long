#include "so_long.h"

// void	put_imagines(t_mlx game, int x, int y)
// {
// 	// if (game.map[x][y] == 'C')
// 	// 	mlx_put_image_to_window(game.mlx_ptr, game.window, game.collect, x * SIZE, y * SIZE);
// 	// if (game.map[x][y] == 'E')
// 	// 	mlx_put_image_to_window(game.mlx_ptr, game.window, game.exit, x * SIZE, y * SIZE);
// 	// if (game.map[x][y] == '0')
// 	// 	mlx_put_image_to_window(game.mlx_ptr, game.window, game.empty, x * SIZE, y * SIZE);
// 	// if (game.map[x][y] == 'P')
// 	// 	mlx_put_image_to_window(game.mlx_ptr, game.window, game.player, x * SIZE, y * SIZE);
// 	if (game.map[x][y] == '1')
// 		mlx_put_image_to_window(game.mlx_ptr, game.window, game.wall, x * SIZE, y * SIZE);
// }

int	images_converter(t_mlx game)
{
	int	size;
	int	*ptr_size;

	size = SIZE;
	ptr_size = &size;
	// game.collect = mlx_xpm_file_to_image(game.mlx_ptr, "images/c_50x50.xpm", ptr_size, ptr_size);
	// if (!game.collect)
	// 	return (write(2, "Error\n", 6), exit_clean_way(&game), 0);
	// game.exit = mlx_xpm_file_to_image(game.mlx_ptr, "images/e_50x50.xpm", ptr_size, ptr_size);
	// if (!game.exit)
	// 	return (write(2, "Error\n", 6), exit_clean_way(&game), 0);
	// game.empty = mlx_xpm_file_to_image(game.mlx_ptr, "images/0_50x50.xpm", ptr_size, ptr_size);
	// if (!game.empty)
	// 	return (write(2, "Error\n", 6), exit_clean_way(&game), 0);
	// game.player = mlx_xpm_file_to_image(game.mlx_ptr, "images/p_50x50.xpm", ptr_size, ptr_size);
	// if (!game.player)
	// 	return (write(2, "Error\n", 6), exit_clean_way(&game), 0);
	game.wall = mlx_xpm_file_to_image(game.mlx_ptr, "images/1_50x50.xpm", &game.width, &game.heigth);
	if (!game.wall)
		return (write(2, "Error\n", 6), exit_clean_way(&game), 0);

	return (1);
}

int	do_mlx(struct s_map map)
{
	t_mlx	game;

	game.width = map.x_max;
	game.heigth = map.y_max;
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (dbl_ptr_free(map.map), 1);
	game.window = mlx_new_window(game.mlx_ptr,
			map.x_max * SIZE, map.y_max * SIZE, "so_long");
	if (!game.window)
		return (dbl_ptr_free(map.map), mlx_destroy_display(game.mlx_ptr),
			free(game.mlx_ptr), write(2, "Error\n", 6), 0);
	game.map = map.map;
	images_converter(game);
	// fill_window(game);
	mlx_hook(game.window, 17, 0, exit_clean_way, &game);
	mlx_key_hook(game.window, handle_keyboard, &game);
	


	mlx_loop(game.mlx_ptr);
	return (exit_clean_way(&game), 1);
}
