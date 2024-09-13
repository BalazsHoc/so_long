#include "so_long.h"

int	exit_clean_way(t_mlx *game)
{
	clean_images(game);
	dbl_ptr_free(game->map);
	mlx_destroy_window(game->mlx_ptr, game->window);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(1);
}

void	clean_images(t_mlx *game)
{
	// if (game->collect)
	// 	mlx_destroy_image(game->mlx_ptr, game->collect);
	// if (game->exit)
	// 	mlx_destroy_image(game->mlx_ptr, game->exit);
	// if (game->empty)
	// 	mlx_destroy_image(game->mlx_ptr, game->empty);
	// if (game->player)
	// 	mlx_destroy_image(game->mlx_ptr, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
}
