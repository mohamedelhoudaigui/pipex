# Source files
SRCS = ./src/libft/printf/ft_printf.c \
       ./src/libft/printf/ft_printf_hex.c \
       ./src/libft/printf/ft_printf_pointer.c \
       ./src/libft/printf/ft_printf_nbr.c \
       ./src/libft/printf/ft_printf_parser.c \
       ./src/libft/printf/ft_printf_str.c \
	   ./src/libft/get_next_line/get_next_line.c \
	   ./src/libft/get_next_line/get_next_line_utils.c \
       ./src/pipex.c \
	   ./src/parsing.c \
	   ./src/err_handler.c \
	   ./src/init_handler.c \
	   ./src/get_path.c \
	   ./src/fd_ctl.c \
	   ./src/here_doc.c \
       ./src/libft/ft_isalpha.c ./src/libft/ft_isprint.c ./src/libft/ft_memcmp.c  ./src/libft/ft_putchar_fd.c ./src/libft/ft_split.c \
	./src/libft/ft_strlcat.c ./src/libft/ft_strncmp.c ./src/libft/ft_substr.c ./src/libft/ft_atoi.c ./src/libft/ft_isalnum.c \
	./src/libft/ft_itoa.c ./src/libft/ft_memcpy.c  ./src/libft/ft_putendl_fd.c ./src/libft/ft_strchr.c  ./src/libft/ft_strlcpy.c \
	./src/libft/ft_strnstr.c ./src/libft/ft_tolower.c ./src/libft/ft_bzero.c   ./src/libft/ft_isascii.c \
	./src/libft/ft_memmove.c ./src/libft/ft_putnbr_fd.c  ./src/libft/ft_strdup.c  ./src/libft/ft_strlen.c  ./src/libft/ft_strrchr.c \
	./src/libft/ft_toupper.c ./src/libft/ft_calloc.c  ./src/libft/ft_isdigit.c ./src/libft/ft_memchr.c  ./src/libft/ft_memset.c  \
	./src/libft/ft_putstr_fd.c  ./src/libft/ft_strjoin.c ./src/libft/ft_strmapi.c ./src/libft/ft_strtrim.c ./src/libft/ft_striteri.c \

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex

all: $(NAME)

$(NAME): $(SRCS) ./src/pipex.h Makefile
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	@$(RM) $(NAME)

fclean: clean

re: clean all

.PHONY: clean