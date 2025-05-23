CX = cc
CXFLAGS = -Wall -Wextra -Werror -g3

SRCS =	main.c \
		parser.c \
		stack.c \
		free.c \
		exit.c \
		sorter.c \
		radix_sorter.c \
		instructions.c \
		base_instructions.c

OBJS = $(SRCS:.c=.o)
OUTPUT = push_swap

LIB_PRINTF = ft_printf/libftprintf.a
LIB_FT = libft/libft.a
LIBS = $(LIB_PRINTF) $(LIB_FT)

all: $(OUTPUT)

$(LIB_PRINTF):
	make -C ft_printf

$(LIB_FT):
	make -C libft

$(OUTPUT): $(OBJS) $(LIBS)
	$(CX) $(CXFLAGS) $(OBJS) -o $(OUTPUT) -I includes $(LIBS)

%.o: %.c
	$(CX) $(CXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C ft_printf
	make clean -C libft

fclean: clean
	rm -f $(OUTPUT)
	rm -f $(LIB_PRINTF)
	rm -f $(LIB_FT)

re: fclean all

.PHONY: all clean fclean re
