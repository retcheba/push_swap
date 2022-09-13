SRCS		= srcs/main.c
OBJS		= $(SRCS:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror 
NAME		= push_swap
RM			= rm -f
LIBFT		= libft/libft.a

all:		$(NAME)

%.o: %.c
			$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
			make -C libft/

$(NAME): 	$(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
			$(RM) $(OBJS)
			make fclean -C libft/

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
