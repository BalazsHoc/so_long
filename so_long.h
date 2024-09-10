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
# include <fcntl.h>

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*mlx_window;
}			t_mlx_data;

struct	s_map
{
	char	**map;
	int		x_max;
	int		y_max;
	int		c;
};

struct s_cord
{
	int	x;
	int	y;
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

//	0cep.c
bool	blocks(struct s_map map);
int		is_c(struct s_map map);
bool	cep01(struct s_map map);
bool	pe(struct s_map map, char pe);

// fincing_route.c
bool	is_peroute(struct s_map map);
bool	route(struct s_map map, struct s_cord p, struct s_cord e);
int		its_y(struct s_map map, char pe);
int		its_x(struct s_map map, char pe);

// stepping.c
void	step(struct s_map map, int cur_x, int cur_y);
void	res_step(struct s_map map, int cur_x, int cur_y);
int		step_col(struct s_map map, int cur_x, int cur_y);

#endif
