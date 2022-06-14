SRCS	=	pipex.c \
			read_args.c \

OBJS	=	${SRCS:%.c=%.o}
BOBJS	=	${BSRCS:%.c=%.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIB		=	-L./library/ft_printf -lftprintf -L./library/libft -lft

NAME	=	pipex

#rules    -------------------------------------------------------------    rules

all:		${NAME}

${NAME}: ${OBJS}	library
	@${CC} ${CFLAGS} ${LIB} ${OBJS} -o ${NAME}
	@echo "code compiled succesfully"

library:	printf libft

printf:
	@make -s -C ./library/ft_printf
	@echo "printf compiled"

libft:
	@make -s -C ./library/libft
	@echo "libft compiled"

clean:
	@rm -rf ${OBJS} ${NAME}.dSYM ${BOBJS} test
	@make -s -C ./library/ft_printf clean
	@make -s -C ./library/libft clean
	@echo "object files removed"

fclean:		clean
	@rm -f ${NAME} generator bonus/checker
	@make -s -C ./library/ft_printf fclean
	@make -s -C ./library/libft fclean
	@echo "${NAME} file removed"

re:		fclean all

debug:	library
	@${CC} ${CFLAGS} ${LIB} ${SRCS} -o ${NAME} -g -fsanitize=address

.PHONY:		all clean fclean re debug bonus
