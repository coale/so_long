NAME = so_long

SRC = src/checks.c src/read.c src/print_map.c src/flood_fill.c src/utils.c src/close.c

LIBFT = libft/libft.a

MLX = minilibx-linux/libmlx.a

MLX_FLAG = -lm -lX11 -lXext

FLAG = -no-pie -Wall -Wextra -Werror

$(NAME):
	make -C libft
	cc $(FLAG) $(SRC) $(LIBFT) $(MLX) $(MLX_FLAG) -o $(NAME)

all: $(NAME)

re: fclean all

clean: 
	make clean -C libft

fclean:
	make fclean -C libft
	rm -rf $(NAME)
	
.PHONY: all re clean fclean
