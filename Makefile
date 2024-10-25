SRCS = 	

BONUS_SRC = 

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRC:.c=.o}

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar rcs

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

${OBJS}: ${SRCS}
	${CC} ${CFLAGS} -c ${SRCS}

bonus: ${NAME} ${BONUS_OBJS}
	${AR} ${NAME} ${BONUS_OBJS} 

${BONUS_OBJS}: ${BONUS_SRC}
	${CC} ${CFLAGS} -c ${BONUS_SRC}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME} 

re: fclean all

.PHONY: all clean fclean re