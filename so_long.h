/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:38:43 by bhocsak           #+#    #+#             */
/*   Updated: 2024/09/06 10:38:45 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "mlx.h"
# include <X11/keysym.h>

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*mlx_window;
}			t_mlx_data;

struct	s_map
{
	int		x_max;
	int		y_max;
	int		p_num;
	int		e_num;
	bool	if_c;
	bool	wall_around;
	char	**map;
};

//	so_long.c
char	**sl_reading(char **argv);
char	**taking_map(char **map, char *line, int num_lines, int fd);
void	dbl_ptr_free(char **map);
void	write_map_out(char **map);	// TAKE THAT OUT

//	checks.c
bool	is_rectangular(char **map);
bool	is_wall_around(struct s_map map);
bool	map_size(struct s_map map);

//	utils_functions.c
int		num_colum(char **map);
int		give_x(struct s_map map);
int		give_y(struct s_map map);

#endif
