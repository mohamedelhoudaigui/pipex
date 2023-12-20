SRCS =	ft_printf.c ft_printf_hex.c ft_printf_pointer.c ft_printf_nbr.c ft_printf_parser.c ft_printf_str.c

OBJS =	$(SRCS:.c=.o)

CC =	cc

RM =	rm -f

CFLAGS =	-c -Wall -Wextra -Werror -g -I.

NAME =	libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o:%.c	ft_printf.h
	$(CC) $(CFLAGS) $<

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
