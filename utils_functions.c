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
	int	j;

	j = 0;
	j = ft_strlen(map.map[0]) - 2;
	return (j);
}

int	give_y(struct s_map map)
{
	int	i;

	i = 0;
	while (map.map[i])
		i++;
	i--;
	return (i);
}
