/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:38:34 by bhocsak           #+#    #+#             */
/*   Updated: 2024/09/06 10:38:37 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_map_out(char **map)
{
	int	i = 0;
	int	j = 0;

	while (map[i])
	{
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		j = 0;
		i++;
	}
}

void	dbl_ptr_free(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
		i++;
	while (i > 0)
		free(map[--i]);
	free(map);
	map = NULL;
}

void	dbl_ptr_free_num(char **temp, int len)
{
	int	i;

	if (!temp)
		return ;
	i = 0;
	
	while (i < len + 2)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	temp = NULL;
}

char	**taking_map(char **map, char *line, int num_lines, int fd)
{
	char	**temp;
	int		j;

	temp = malloc(sizeof(char *) * (num_lines + 1));
	if (!temp)
		return (get_next_line(fd, 1), gnl_free(&line),
			dbl_ptr_free(temp), dbl_ptr_free(map), NULL);
	j = 0;
	while (j < num_lines - 1)
	{
		temp[j] = map[j];
		j++;
	}
	temp[j] = ft_strdup(line); //its failing
	if (!temp[j])
		return (get_next_line(fd, 1), gnl_free(&line),
			dbl_ptr_free_num(temp, j), dbl_ptr_free(map), NULL);
	temp[++j] = NULL;
	if (map)
		free(map);
	return (temp);
}

char	**sl_reading(char **argv)
{
	char	**map;
	char	*line;
	int		fd;
	int		num_lines;
	bool	flag;

	flag = 0;
	map = NULL;
	num_lines = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (close(fd), NULL);
	line = get_next_line(fd, flag);
	while (line)
	{
		map = taking_map(map, line, num_lines, fd);
		if (!map)
			return (close(fd), NULL);
		num_lines++;
		free(line);
		line = get_next_line(fd, flag);
	}
	return (get_next_line(fd, 1), gnl_free(&line), close(fd), map);
}

int	main(int argc, char **argv)
{
	struct s_map	map;

	if (argc != 2)
		return (ft_printf("No or too much argument\n"), 1);
	map.map = sl_reading(argv);
	if (!map.map)
		return (ft_printf("Invalid map\n"), 1);
	if (!is_rectangular(map.map))
		return (ft_printf("Map must be rectangular\n"),
			dbl_ptr_free(map.map), 1);
	map.x = give_x(map);
	map.y = give_y(map);
	write_map_out(map.map);
	if (!map_size(map))
		return (ft_printf("Wrong mapsize\n"), dbl_ptr_free(map.map), 1);
	if (!is_wall_around(map))
		return (ft_printf("Map must be surrounded by walls\n"),
			dbl_ptr_free(map.map), 1);
	if (!blocks(map))
		return (dbl_ptr_free(map.map), 1);

	dbl_ptr_free(map.map);
	return (0);
}
