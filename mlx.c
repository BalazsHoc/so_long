#include "so_long.h"

int	handle_keyboard(int key, t_mlx_data *data)
{
	if (key == XK_Escape)
	{
		ft_printf("The %d kes (ESC) has been pressed\n\n", key);
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		dbl_ptr_free(data->map);
		exit(1);
	}
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

int	do_mlx(struct s_map map)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (dbl_ptr_free(map.map), 1);
	data.mlx_window = mlx_new_window(data.mlx_ptr,
			map.x_max * 100, map.y_max * 100, "so_long");
	if (!data.mlx_window)
		return (dbl_ptr_free(map.map), mlx_destroy_display(data.mlx_ptr),
			free(data.mlx_ptr), write(2, "Error, mlx malloc failed\n", 25), 0);
	data.map = map.map;
	mlx_key_hook(data.mlx_window, handle_keyboard, &data);


	mlx_loop(data.mlx_ptr);
	return (mlx_destroy_window(data.mlx_ptr, data.mlx_window),
		mlx_destroy_display(data.mlx_ptr), free(data.mlx_ptr),
		dbl_ptr_free(data.map), 1);
}
