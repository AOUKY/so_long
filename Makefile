SRCS = so_long.c check_map.c file.c img_mv.c
NAME = so_long
CC = cc
LIBMLX	= MLX42

LIBS	= $(LIBMLX)/build/libmlx42.a -I"$(LIBMLX)/include/MLX42/MLX42.h" -lglfw -L"/Users/haouky/.brew/opt/glfw/lib/"
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast
GFLAGS	= -Wextra -Wall -Werror 

GNL = Get_Next_Line/get_next_line.c Get_Next_Line/get_next_line_utils.c
PRINTF = ft_printf/libftprintf.a
DPRINT = ft_printf
LIBFT = libft/libft.a
DLIBFT = libft
HEDER = so_long.h
OBJS = ${SRCS:.c=.o}
OGL = ${GNL:.c=.o}

all: libmlx $(NAME)

$(NAME): $(OBJS) $(PRINTF) $(LIBFT) $(OGL)
		$(CC) $(GFLAGS) $(OBJS) $(PRINTF) $(LIBFT) $(OGL) $(LIBS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< 

$(PRINTF):
	make -C $(DPRINT)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	make -C $(DLIBFT)
	make -C $(DLIBFT) bonus

clean:
	make -C $(DPRINT) fclean
	make -C $(DLIBFT) fclean
	rm -rf $(OBJS) $(OGL)
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx