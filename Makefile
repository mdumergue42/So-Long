SRCS =	ft_parsing_map.c \
		ft_map.c \
		ft_check_error.c \
		ft_error.c \
		ft_check_error_utils.c \
		ft_free.c \
		ft_mov.c \
		ft_mov_utils.c \
		ft_utils.c \
		main.c \
		GNL/get_next_line.c \
		GNL/get_next_line_utils.c

NAME    = so_long

OBJS    =  $(SRCS:.c=.o)

HEADERS    = includes/

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = minilibx-linux/libmlx.a

LIBFT = Libft/libft.a

PRINTF = Ft_Printf/printf.a

all : $(NAME)

$(NAME) : $(OBJS) $(MLX) $(LIBFT) $(PRINTF)
	$(CC) $(FLAGS) $(OBJS) $(MLX) $(LIBFT) $(PRINTF) -o $(NAME) -lXext -lX11 

%.o : %.c
	$(CC) $(FLAGS) -ILibft -IFt_Printf -Iminilibx-linux -IGNL -o $@ -c $<  

$(MLX) :
	make -C minilibx-linux

$(LIBFT) :
	make -C Libft

$(PRINTF) :
	make -C Ft_Printf

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	make -C ./Libft fclean
	make -C ./Ft_Printf fclean
	make -C minilibx-linux clean

re : fclean all

.PHONY : all library clean fclean re
