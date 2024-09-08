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

GET_NEXT_LINE_PATH = get_next_line/
GET_NEXT_LINE = $(GET_NEXT_LINE_PATH)get_next_line.a

FT_PRINTF_PATH = ft_printf/
FT_PRINTF = $(FT_PRINTF_PATH)libftprintf.a

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a


CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLXFLAGS = -lmlx -lXext -lX11 -lm

SRCS = so_long.c mlx.c checks.c utils_functions.c 0cep.c

OBJ = $(SRCS:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): systems $(OBJ)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)

systems:
	@make -C $(LIBFT_PATH) all
	@make -C $(FT_PRINTF_PATH) all
	@make -C $(GET_NEXT_LINE_PATH) all

all: systems $(NAME)

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(FT_PRINTF_PATH) clean
	@make -C $(GET_NEXT_LINE_PATH) clean
	rm -f $(OBJ)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(FT_PRINTF_PATH) fclean
	@make -C $(GET_NEXT_LINE_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
