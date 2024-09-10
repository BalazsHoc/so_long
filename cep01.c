/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cep01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:33:15 by bhocsak           #+#    #+#             */
/*   Updated: 2024/09/10 10:33:23 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	pe(struct s_map map, char pe)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i <= map.y)
	{
		while (j <= map.x)
		{
			if (map.map[i][j] == pe)
				count++;
			if (count > 1)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if (count == 0)
		return (0);
	return (1);
}

int	is_collectable(struct s_map map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i <= map.y)
	{
		while (j <= map.x)
		{
			if (map.map[i][j] == 'C')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

bool	cep01(struct s_map map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= map.y)
	{
		while (j <= map.x)
		{
			if (map.map[i][j] != 'C' && map.map[i][j] != 'E'
				&& map.map[i][j] != 'P' && map.map[i][j] != '0'
					&& map.map[i][j] != '1')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

bool	blocks(struct s_map map)
{
	if (!pe(map, 'P'))
		return (ft_printf("One PLAYER needed on the map\n"), 0);
	if (!pe(map, 'E'))
		return (ft_printf("One EXIT needed on the map\n"), 0);
	if (!is_collectable(map))
		return (ft_printf("Minimum is one COLLECTABLE item on the map\n"), 0);
	if (!cep01(map))
		return (ft_printf("Unexpected character in Map\n"), 0);
	return (1);
}
