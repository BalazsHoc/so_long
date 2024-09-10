/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stepping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:38:58 by bhocsak           #+#    #+#             */
/*   Updated: 2024/09/10 19:39:01 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	step_col(struct s_map map, int cur_x, int cur_y)
{
	if (cur_x == map.x_max || cur_y == map.y_max)
		return (0);
	if (map.map[cur_y][cur_x] == 'c' || map.map[cur_y][cur_x] == 'e'
		|| map.map[cur_y][cur_x] == 'p' || map.map[cur_y][cur_x] == 'o'
			|| map.map[cur_y][cur_x] == '1')
		return (0);
	if (map.map[cur_y][cur_x] == 'C')
	{
		map.map[cur_y][cur_x] = ft_tolower(map.map[cur_y][cur_x]);
		return (1 + step_col(map, cur_x + 1, cur_y)
			+ step_col(map, cur_x, cur_y + 1)
			+ step_col(map, cur_x - 1, cur_y)
			+ step_col(map, cur_x, cur_y - 1));
	}
	if (map.map[cur_y][cur_x] == 'C' || map.map[cur_y][cur_x] == 'E'
		|| map.map[cur_y][cur_x] == 'P')
		map.map[cur_y][cur_x] = ft_tolower(map.map[cur_y][cur_x]);
	if (map.map[cur_y][cur_x] == '0')
		map.map[cur_y][cur_x] = 'o';
	return (0 + step_col(map, cur_x + 1, cur_y)
		+ step_col(map, cur_x, cur_y + 1)
		+ step_col(map, cur_x - 1, cur_y)
		+ step_col(map, cur_x, cur_y - 1));
}

void	res_step(struct s_map map, int cur_x, int cur_y)
{
	if (cur_x == map.x_max || cur_y == map.y_max)
		return ;
	if (map.map[cur_y][cur_x] == 'C' || map.map[cur_y][cur_x] == 'E'
		|| map.map[cur_y][cur_x] == 'P' || map.map[cur_y][cur_x] == '0'
			|| map.map[cur_y][cur_x] == '1')
		return ;
	if (map.map[cur_y][cur_x] == 'c' || map.map[cur_y][cur_x] == 'e'
		|| map.map[cur_y][cur_x] == 'p')
		map.map[cur_y][cur_x] = ft_toupper(map.map[cur_y][cur_x]);
	if (map.map[cur_y][cur_x] == 'o')
		map.map[cur_y][cur_x] = '0';
	res_step(map, cur_x + 1, cur_y);
	res_step(map, cur_x, cur_y + 1);
	res_step(map, cur_x - 1, cur_y);
	res_step(map, cur_x, cur_y - 1);
}

void	step(struct s_map map, int cur_x, int cur_y)
{
	if (cur_x == map.x_max || cur_y == map.y_max)
		return ;
	if (map.map[cur_y][cur_x] == 'c' || map.map[cur_y][cur_x] == 'e'
		|| map.map[cur_y][cur_x] == 'p' || map.map[cur_y][cur_x] == 'o'
			|| map.map[cur_y][cur_x] == '1')
		return ;
	if (map.map[cur_y][cur_x] == 'C' || map.map[cur_y][cur_x] == 'E'
		|| map.map[cur_y][cur_x] == 'P')
		map.map[cur_y][cur_x] = ft_tolower(map.map[cur_y][cur_x]);
	if (map.map[cur_y][cur_x] == '0')
		map.map[cur_y][cur_x] = 'o';
	step(map, cur_x + 1, cur_y);
	step(map, cur_x, cur_y + 1);
	step(map, cur_x - 1, cur_y);
	step(map, cur_x, cur_y - 1);
}
