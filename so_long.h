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

# define SIZE 50

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*window;
	char	**map;

	int		width;
	int		heigth;
	int		c_num;

	int		p_x;
	int		p_y;

	void	*collect;
	void	*exit;
	void	*empty;
	void	*player;
	void	*wall;

	int		steps;
}			t_mlx;

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

//	checks.c
bool	is_rectangular(char **map);
bool	is_wall_around(struct s_map map);
bool	map_size(struct s_map map);
bool	name_of_map(char *map_name);

//	utils_functions.c
int		num_colum(char **map);
int		give_x(struct s_map map);
int		give_y(struct s_map map);

//	0cep.c
bool	exist_reachable(struct s_map map);
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

// mlx.c
int		do_mlx(struct s_map map);
void	convert(t_mlx *game, void **image_ptr, char *xpm_file_path);
void	images_converter(t_mlx *game);
void	put_images(t_mlx *game, int x, int y);

// mlx_cleaning.c
int		exit_clean_way(t_mlx *game);
int		exit_clean_way_won(t_mlx *game);

// mlx_keyhandler.c
int		handle_keyboard(int key, t_mlx *game);
int		handle_click_x(t_mlx *game);
void	fill_up_window(t_mlx *game);

// wasd.c
int		moving_w(t_mlx *game);
int		moving_a(t_mlx *game);
int		moving_s(t_mlx *game);
int		moving_d(t_mlx *game);

#endif
