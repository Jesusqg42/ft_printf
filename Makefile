NAME = libftprintf.a

SRCS = ft_printf.c \
	ft_strlen.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putpointer.c \
	ft_putnbr.c \
	ft_putnosign.c \
	ft_puthexa.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@${AR} ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re