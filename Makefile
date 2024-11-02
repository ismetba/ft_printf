NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putlnbr_base.c ft_putunbr_base.c ft_check_base.c \
	ft_string_format.c ft_integer_format.c ft_pointer_format.c ft_unsigned_format.c ft_hex_format.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

AR = ar rcs


all: ${NAME}

${NAME}: ${OBJS}
	$(MAKE) bonus -C ./Libft
	cp ./Libft/libft.a $(NAME)
	${AR} ${NAME} ${OBJS}

${OBJS}: ${SRCS}
	${CC} ${CFLAGS} -c ${SRCS}


bonus:
	

clean:
	$(MAKE) clean -C ./Libft
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 
	${RM} ./Libft/libft.a

re: fclean all

.PHONY:	all clean fclean re bonus
