NAME = so_long

SRC = src/checks.c src/read.c src/print_map.c src/flood_fill.c src/utils.c src/close.c

OBJ_S = $(SRC:.c=.o)

LIBFT = libft/libft.a

MLX = minilibx-linux/libmlx.a

MLX_FLAG = -lm -lX11 -lXext

FLAG = -no-pie -Wall -Wextra -Werror -g

$(NAME): $(OBJ_S)
	@make -C libft
	@cc $(FLAG) $(SRC) $(LIBFT) $(MLX) $(MLX_FLAG) -o $(NAME)


all: $(NAME)

re: fclean all

clean: 
	rm -f ${OBJ_S}
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)
	
.PHONY: all re clean fclean
