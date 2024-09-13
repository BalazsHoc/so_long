#include "so_long.h"

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

// void	fill_window(t_mlx game)
// {
// 	put_imagines(game, 1, 1);
// 	// int	i;
// 	// int	j;

// 	// i = 0;
// 	// j = 0;
// 	// while (i < game.heigth)
// 	// {
// 	// 	while (j < game.width)
// 	// 	{
// 	// 		put_imagines(game, j, i);
// 	// 		j++;
// 	// 	}
// 	// 	j = 0;
// 	// 	i++;
// 	// }
// }
