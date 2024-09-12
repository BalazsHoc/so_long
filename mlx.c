#include "so_long.h"

int	put_imagines(t_mlx game, int x, int y)
{
	if (game.map[x][y] == 'C')
		mlx_put_image_to_window(game.mlx_ptr, game.window, "images/c_50x50.xpm", x * SIZE, y * SIZE);
	if (game.map[x][y] == 'E')
		mlx_put_image_to_window(game.mlx_ptr, game.window, "images/e_50x50.xpm", x * SIZE, y * SIZE);
	if (game.map[x][y] == '0')
		mlx_put_image_to_window(game.mlx_ptr, game.window, "images/0_50x50.xpm", x * SIZE, y * SIZE);
	if (game.map[x][y] == 'P')
		mlx_put_image_to_window(game.mlx_ptr, game.window, "images/p_50x50.xpm", x * SIZE, y * SIZE);
	if (game.map[x][y] == '1')
		mlx_put_image_to_window(game.mlx_ptr, game.window, "images/1_50x50.xpm", x * SIZE, y * SIZE);
	return (1);
}

void	fill_window(t_mlx game, struct s_map map)
{
	(void)map;
	mlx_put_image_to_window(game.mlx_ptr, game.window, "images/c_50x50.xpm", 1 * SIZE, 1 * SIZE);
	// int	i;
	// int	j;

	// i = 0;
	// j = 0;
	// while (i < map.y_max)
	// {
	// 	while (j < map.x_max)
	// 	{
	// 		put_imagines(game, j, i);
	// 		j++;
	// 	}
	// 	j = 0;
	// 	i++;
	// }
}

int	handle_keyboard(int key, t_mlx *game)
{
	if (key == XK_Escape)
	{
		ft_printf("The %d kes (ESC) has been pressed\n\n", key);
		exit_clean_way(game);
	}
	(void)game;
	if (key == XK_w)
		ft_printf("w\n\n");
	if (key == XK_a)
		ft_printf("a\n\n");
	if (key == XK_s)
		ft_printf("s\n\n");
	if (key == XK_d)
		ft_printf("s\n\n");
	return (0);
}
int	exit_clean_way(t_mlx *game)
{
	mlx_destroy_window(game->mlx_ptr, game->window);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	dbl_ptr_free(game->map);
	exit(1);
}

int	do_mlx(struct s_map map)
{
	t_mlx	game;

	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (dbl_ptr_free(map.map), 1);
	game.window = mlx_new_window(game.mlx_ptr,
			map.x_max * SIZE, map.y_max * SIZE, "so_long");
	if (!game.window)
		return (dbl_ptr_free(map.map), mlx_destroy_display(game.mlx_ptr),
			free(game.mlx_ptr), write(2, "Error, mlx malloc failed\n", 25), 0);
	game.map = map.map;
	// fill_window(game, map);
	mlx_hook(game.window, 17, 0, exit_clean_way, &game);
	mlx_key_hook(game.window, handle_keyboard, &game);
	


	mlx_loop(game.mlx_ptr);
	return (exit_clean_way(&game), 1);
}
