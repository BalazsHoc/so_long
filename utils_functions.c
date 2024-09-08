/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:07:57 by bhocsak           #+#    #+#             */
/*   Updated: 2024/09/08 17:08:00 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	num_colum(char **map)
{
	int	num;

	num = 0;
	while (map[num])
		num++;
	return (num);
}

int	give_x(struct s_map map)
{
	map.x_max = ft_strlen(map.map[0]) - 2;
	return (map.x_max);
}

int	give_y(struct s_map map)
{
	while (map.map[map.y_max])
		map.y_max++;
	map.y_max--;
	return (map.y_max);
}
