NAME = libftprintf.a

SRCS = ft_printf.c \
	ft_strlen.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putpointer.c \
	ft_putnbr.c \
	ft_putnosign.c \
	ft_puthexa_min.c \
	ft_puthexa_may.c

INCLUDE = ft_printf.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

%.o: %.c ${INCLUDE}
	@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.c=.o}

${NAME}: ${OBJS}
	@${AR} ${NAME} ${OBJS}

all: ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re