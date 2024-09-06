# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 11:14:20 by bhocsak           #+#    #+#              #
#    Updated: 2024/09/06 11:14:25 by bhocsak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FT_PRINTF_PATH = ft_printf/
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

MLX_PATH = minilibx-linux/
MLX = $(MLX_PATH)libmlx.a

MLX_FLAGS = S = -Lmlx -lmlx -framework OpenGL -framework App;

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS =

OBJ = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX) -o $(NAME)

systems:
	@make -C $(LIBFT_PATH) all
	@make -C $(FT_PRINTF_PATH) all
	@make -C $(MLX_PATH) all

all: systems $(NAME)

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(FT_PRINTF_PATH) clean
	@make -C $(MLX_PATH) clean
	rm -f $(OBJ)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(FT_PRINTF_PATH) fclean
	@make -C $(MLX_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
