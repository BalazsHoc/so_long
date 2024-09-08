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
	while (j <= map.x)
	{
		if (j == 0 || j == map.x)
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
	while (i <= map.y)
	{
		j = 0;
		if (i == 0 || i == map.y)
		{
			while (j <= map.x)
			{
				if (map.map[i][j] != '1')
					return (0);
				j++;
			}
		}
		j = 0;
		if (i != 0 && i != map.y)
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
	map.x = 0;
	map.y = 0;
	if (!map.map[map.y][map.x])
		return (0);
	while (map.map[0][map.x])
		map.x++;
	map.x--;
	while (map.y < num_colum(map.map))
		map.y++;
	if ((map.y > 2 && map.x > 4) || (map.y > 4 && map.x > 2))
	{
		if ((map.y < 9 && map.x < 16)
			|| (map.y < 16 && map.x < 9))
			return (1);
	}
	return (0);
}
