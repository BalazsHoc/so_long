/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:34:57 by bhocsak           #+#    #+#             */
/*   Updated: 2024/09/07 13:35:00 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	middle_lines(struct s_map map, char *str, int j)
{
	while (j <= map.x_max)
	{
		if (j == 0 || j == map.x_max)
		{
			if (str[j] != '1')
				return (0);
		}
		j++;
	}
	return (1);
}

bool	is_wall_around(struct s_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i <= map.y_max)
	{
		j = 0;
		if (i == 0 || i == map.y_max)
		{
			while (j <= map.x_max)
			{
				if (map.map[i][j] != '1')
					return (0);
				j++;
			}
		}
		j = 0;
		if (i != 0 && i != map.y_max)
		{
			if (!middle_lines(map, map.map[i], j))
				return (0);
		}
		i++;
	}
	return (1);
}

bool	is_rectangular(char **map)
{
	size_t	len;
	int		i;
	int		last_colum;

	last_colum = num_colum(map) - 1;
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i] && i < last_colum)
	{
		if (len != ft_strlen(map[i]))
			return (0);
		i++;
	}
	if (i == last_colum)
	{
		if (len - 1 != ft_strlen(map[i]))
			return (0);
	}
	return (1);
}

bool	map_size(struct s_map map)
{
	map.x_max = 0;
	map.y_max = 0;
	if (!map.map[map.y_max][map.x_max])
		return (0);
	while (map.map[0][map.x_max])
		map.x_max++;
	map.x_max--;
	while (map.y_max < num_colum(map.map))
		map.y_max++;
	if ((map.y_max > 2 && map.x_max > 4) || (map.y_max > 4 && map.x_max > 2))
	{
		if (map.y_max < 9 && map.x_max < 16)
			return (1);
	}
	return (0);
}
