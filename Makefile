SRCS		= main.c radix_bin.c chained_list.c index_list.c parsing.c push_swap_utils.c algo_for_3.c algo_DIY.c param_error.c
OBJS		= $(addprefix srcs/, $(SRCS:.c=.o))
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror 
NAME		= push_swap
RM			= rm -f
LIBFT		= libft/libft.a

all:		$(NAME)

%.o: %.c
			@$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
			@make -s -C libft/

$(NAME): 	$(OBJS) $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
			@echo "\e[96m# ************************ #"
			@echo "\e[96m#                          #"
			@echo "\e[96m#      make completed      #"
			@echo "\e[96m#                          #"
			@echo "\e[96m# ************************ #"

clean:
			@$(RM) $(OBJS)
			@make -s fclean -C libft/
			@echo "\e[96m# ************************ #"
			@echo "\e[96m#                          #"
			@echo "\e[96m#   make clean completed   #"
			@echo "\e[96m#                          #"
			@echo "\e[96m# ************************ #"

fclean:		clean
			@$(RM) $(NAME)
			@echo "\e[96m# ************************ #"
			@echo "\e[96m#                          #"
			@echo "\e[96m#  make fclean completed   #"
			@echo "\e[96m#                          #"
			@echo "\e[96m# ************************ #"

re:			fclean all

.PHONY:		all clean fclean re
