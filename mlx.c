#include "so_long.h"

int	main(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);

	mlx_destroy_display(mlx_ptr);
}