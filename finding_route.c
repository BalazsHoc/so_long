#include "so_long.h"

int	its_x(struct s_map map, char pe)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= map.y_max)
	{
		while (j <= map.x_max)
		{
			if (map.map[i][j] == pe)
				return (j);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	its_y(struct s_map map, char pe)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= map.y_max)
	{
		while (j <= map.x_max)
		{
			if (map.map[i][j] == pe)
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

bool	route(struct s_map map, struct s_cord p, struct s_cord e)
{
	int	c;

	c = 0;
	step(map, p.x, p.y);
	if (map.map[e.y][e.x] != 'e')
		return (0);
	res_step(map, p.x, p.y);
	c = step_col(map, p.x, p.y);
	ft_printf("all c: %d | c found: %d\n", map.c, c);
	if (c != map.c)
	{
		dbl_ptr_free(map.map);
		ft_printf("Not all the Collectable items can be reached\n");
		exit(EXIT_FAILURE);
	}
	res_step(map, p.x, p.y);
	return (1);
}

bool	is_peroute(struct s_map map)
{
	struct s_cord	p;
	struct s_cord	e;

	p.x = its_x(map, 'P');
	p.y = its_y(map, 'P');
	e.x = its_x(map, 'E');
	e.y = its_y(map, 'E');

	ft_printf("\ny_max: %d | x_max: %d", map.y_max, map.x_max);
	ft_printf("P[%d][%d]\n", p.y, p.x);
	ft_printf("E[%d][%d]\n", e.y, e.x);
	if (!route(map, p, e))
		return (0);
	return (1);
}
