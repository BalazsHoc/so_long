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

void	dbl_ptr_free(char **map)
{
	int i = 0;

	if (!map)
		return;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**taking_map(char **map, char *line, int num_lines, int fd)
{
	char	**temp;
	int		j;

	temp = malloc(sizeof(char *) * (num_lines + 1));
	if (!temp)
		return (dbl_ptr_free(map), NULL);
	j = 0;
	while (j < num_lines - 1)
	{
		temp[j] = map[j];
		j++;
	}
	temp[j] = ft_strdup(line);
	if (!temp[j])
	{
		while(j > 0)
			free(temp[--j]);
		free(temp);
		return (get_next_line(fd, 1), dbl_ptr_free(map), NULL);
	}
	temp[++j] = NULL;
	if (map)
		free(map);
	return (temp);
}

char	**sl_reading(char **argv)
{
	char	**map = NULL;
	char	*line;
	int		fd;
	int		num_lines;

	map = NULL;
	num_lines = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (close(fd), NULL);
	line = get_next_line(fd, 0);
	if (!line)
		return (close(fd), NULL);
	while (line)
	{
		map = taking_map(map, line, num_lines, fd);
		if (!map)
			return (get_next_line(fd, 1), gnl_free(&line), close(fd), NULL);
		num_lines++;
		free(line);
		line = get_next_line(fd, 0);
	}
	return (gnl_free(&line), close(fd), map);
}

int	main(int argc, char **argv)
{
	struct s_map	map;

	if (argc != 2)
		return (ft_printf("No or too much argument\n"), 1);
	map.map = sl_reading(argv);
	if (!map.map)
		return (ft_printf("Invalid map\n"), 1);
	if (is_rectangular(map.map) == 0)
		return (ft_printf("Map must be rectangular\n"), dbl_ptr_free(map.map), 1);
	if (!is_wall_around(map.map))
		return (ft_printf("Map must be surrounded by walls\n"), dbl_ptr_free(map.map), 1);

	dbl_ptr_free(map.map);
	return (0);
}
