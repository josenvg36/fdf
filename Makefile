NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX_REPO = https://github.com/42Paris/minilibx-linux.git
MLX_DIR = includes/minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

SRCS = main.c read_map.c read_map_utils.c hooks.c free_functions.c isometric.c fdf.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = includes/libft
LIBFT = includes/libft/libft.a
INCLUDES = -I get_next_line -I libft -I $(MLX_DIR) -I .

# Rules
all: $(MLX_DIR) $(NAME)

$(MLX_DIR):
	@if [ ! -d "$(MLIX_DIR)" ]; then \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi

$(NAME): $(OBJS) $(LIBFT) $(MLX_DIR)/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(MINILIBX_DIR)