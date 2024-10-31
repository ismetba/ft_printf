NAME = libftprintf.a

SRCS = src/ft_printf.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar rcs


all: ${NAME}

${NAME}: ${OBJS}
	cp includes/libft.a $(NAME)
	${AR} ${NAME} ${OBJS}

${OBJS}: ${SRCS}
	${CC} ${CFLAGS} -c ${SRCS} -o ${OBJS}


clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 

re: fclean all

.PHONY: all clean fclean re