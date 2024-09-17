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

MINILIBX_PATH = minilibx-linux/
MINILIBX = $(MINILIBX_PATH)minilibx.a

GET_NEXT_LINE_PATH = get_next_line/
GET_NEXT_LINE = $(GET_NEXT_LINE_PATH)get_next_line.a

FT_PRINTF_PATH = ft_printf/
FT_PRINTF = $(FT_PRINTF_PATH)libftprintf.a

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a


CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -L$(MINILIBX_PATH) -lmlx_Linux -lXext -lX11 -lm
#-lXext -lX11 -lm -lmlx 

SRCS =	so_long.c mlx.c checks.c utils_functions.c\
		cep01.c finding_route.c stepping.c mlx_cleaning.c\
		mlx_keyhandler.c wasd.c

OBJ = $(SRCS:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH) all
	@make -C $(FT_PRINTF_PATH) all
	@make -C $(GET_NEXT_LINE_PATH) all
	@make -C $(MINILIBX_PATH) all
	@$(CC) $(CFLAGS) $(OBJ) -L$(MINILIBX_PATH) -lmlx_Linux $(MLXFLAGS) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)
#	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)

all: $(NAME)

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(FT_PRINTF_PATH) clean
	@make -C $(GET_NEXT_LINE_PATH) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(FT_PRINTF_PATH) fclean
	@make -C $(GET_NEXT_LINE_PATH) fclean
	@make -C $(MINILIBX_PATH) clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
