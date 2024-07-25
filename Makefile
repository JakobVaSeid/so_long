NAME = so_long
FT_PRINTF = ft_printf
SOURCES = so_long.c init_game.c movement.c validate.c free.c create_map.c read_map.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I. -I./ft_printf
LIBXFLAGS = -lmlx -lXext -lX11
AR = ar
RM = rm

all: $(NAME)

$(NAME): $(OBJECTS)						
	@make -C $(FT_PRINTF)
	$(CC) $(OBJECTS) $(CFLAGS) $(LIBXFLAGS) -o $(NAME) ft_printf/libftprintf.a

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJECTS)
	@make clean -sC $(FT_PRINTF)

fclean:
	@$(RM) -rf $(OBJECTS)
	@make fclean -sC $(FT_PRINTF)
	@$(RM) -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re