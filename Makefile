NAME = so_long.a
NAME_EXEC = so_long
FT_PRINTF = ft_printf
SOURCES = so_long.c read_map.c check_map.c create_map.c free.c valid_path_check.c handle_input.c get_next_line.c get_next_line_utils.c
OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I. -I./ft_printf
LIBXFLAGS = -lmlx -lXext -lX11
AR = ar
RM = rm

all: $(NAME) $(NAME_EXEC)

$(NAME_EXEC):
	@$(CC) $(CFLAGS) $(LIBXFLAGS) -o $@ $(NAME)

$(NAME): $(OBJECTS)						
	@make -C $(FT_PRINTF)
	@cp ft_printf/libftprintf.a .
	@mv libftprintf.a $(NAME)				
	@$(AR) -rcs $(NAME) $(OBJECTS)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJECTS)
	@make clean --no-print-directory -C $(FT_PRINTF)

fclean:
	@$(RM) -rf $(OBJECTS)
	@make clean --no-print-directory -C $(FT_PRINTF)
	@$(RM) -rf $(NAME)
	@$(RM) -rf $(FT_PRINTF)/libftprintf.a
	@$(RM) -rf $(FT_PRINTF)/libft/libft.a
	@$(RM) -rf $(NAME_EXEC)

re: fclean all

.PHONY: all clean fclean re