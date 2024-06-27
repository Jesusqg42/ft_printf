NAME = libftprintf.a

SRCS = ft_printf.c \

INCLUDE = ft_printf.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

%.o: %.c ${INCLUDE}
	@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@${AR} ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS}

fclean:
	@${RM} ${OBJS}
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re