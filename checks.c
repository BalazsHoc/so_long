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

bool	is_rectangular(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (len != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

bool	is_wall_around(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (i == 0 || !map[i + 1])
		{
			while (map[i][j] && map[i][j] == '\n' && map[i][j] == '1')
				j++;
			if (map[i][j])
				return (0);
		}
		j = 0;
		ft_printf("Penis\n");
		while (i != 0 && !map[i + 1] && map[i][j])
		{
			if ((j = 0 || !map[i][j + 2]) && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
