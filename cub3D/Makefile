PROG	= cub3d

SRCS 	= src/main.c src/check_args.c src/fill_map_vals.c
OBJS 	= ${SRCS:.c=.o}
HEADER	= -Iincludes
MLX 	= -L./minilibx -lmlx -Imlx -lXext -lX11 -lz -lm

CC 		= gcc
CFLAGS 	= -Wall -Wextra -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${PROG}

${PROG}:	${OBJS}
					@echo "\033[33m----Compiling lib----"
					@make re -C ./libft
					@echo "LIBFTMADE"
					@$(CC) ${OBJS} -Llibft -lft ${MLX} -o ${PROG}
					@echo "\033[32mcub3d! Compiled!!ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

clean:
					@make clean -C ./libft
					@rm -f ${OBJS}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f $(NAME)
					@rm -f ${PROG}
					@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:			fclean all

party:
					@printf "\033c"
					@echo "\n\033[35m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[1;33m♪┗(・o･)┓♪"
					@sleep 1
					@printf "\033c"
					@echo "\n\033[36m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[34m♪┗(・o･)┓♪\n"

.PHONY: all clean fclean re
