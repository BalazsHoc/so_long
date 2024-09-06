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

void	dblptr_free(char **dblptr)
{
	int	i;

	i = 0;
	while (dblptr[i])
	{
		free(dblptr[i]);
		i++;
	}
}

// char	**taking_map(char **map, char *line, int num_lines)
// {
// 	char	**temp;
// 	int		i;

// 	temp = malloc(sizeof(char *) * (num_lines + 1));
// 	if (!temp)
// 		return(dblptr_free(map), NULL);
// 	i = 0;
// 	while (map && map[i])
// 	{
// 		ft_printf("PENIS\n");
// 		temp[i] = ft_strdup(map[i]);
// 		i++;
// 	}
// 	temp[i++] = line;
// 	temp[i] = NULL;
// 	if (map)
// 		dblptr_free(map);
// 	return (temp);
// }

char	**sl_reading(char **argv)
{
	char	**map;
	char	*line;
	int		fd;
	int		num_lines;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("Invalid map\n"), NULL);
	line = get_next_line(fd, 0);
	if (!line)
		return (ft_printf("Invalid map\n"), NULL);
	num_lines = 1;
	while (line)
	{
		map = NULL; //taking_map(map, line, num_lines);
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
	dblptr_free(map.map);
	return (0);
}
