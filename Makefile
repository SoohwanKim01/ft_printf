NAME	=	libftprintf.a
LIB		=	./
SRC		=	ft_printf.c ft_print_pointers.c ft_print_text.c ft_nbrbase.c\
			ft_print_numbers.c ft_print_unsigned.c\
			$(LIB)ft_strchr.c $(LIB)ft_putchar_fd.c $(LIB)ft_putstr_fd.c\
		   	$(LIB)ft_isdigit.c $(LIB)ft_putnbr_fd.c $(LIB)ft_strlen.c
OBJS	=	$(SRC:.c=.o)
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(SRC) -c
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) $(NAME)

re: fclean all
