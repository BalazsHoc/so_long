#include "so_long.h"

int	handle_input(int key, t_mlx_data *data)
{
	if (key == XK_Escape)
	{
		printf("The %d kes (ESC) has been pressed\n\n", key);
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	printf("The %d kes has been pressed\n\n", key);
	return (0);
}

int	mlx_my(void)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.mlx_window = mlx_new_window(data.mlx_ptr, 400, 400, "I  created");
	if (!data.mlx_window)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}
	mlx_key_hook(data.mlx_window, handle_input, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.mlx_window);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
