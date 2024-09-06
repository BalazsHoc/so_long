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

typedef struct	s_mlx_data
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

#endif
