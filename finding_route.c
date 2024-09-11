/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_route.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:38:45 by bhocsak           #+#    #+#             */
/*   Updated: 2024/09/10 19:38:47 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (write(2, "Error, no route between Player and Exit\n", 40), 0);
	res_step(map, p.x, p.y);
	c = step_col(map, p.x, p.y);
	if (c != map.c)
		return (write(2, "Error, Collectable item blocked\n", 32), 0);
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
	if (!route(map, p, e))
		return (0);
	return (1);
}
