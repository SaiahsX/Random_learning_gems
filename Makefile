# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 16:30:26 by pchennia          #+#    #+#              #
#    Updated: 2024/02/29 15:13:28 by oadewumi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

B_NAME = checker_Mac

CFILES = rule1_swap.c rule2_rotate.c rule3_reverse_rotate.c rule4_push.c \
		 push_swap.c validate_args.c validate_args_helpers.c sorting.c  \
		 sort_stack_a.c sort_stack_b.c sorting_helpers.c algorithm.c \
		 apply_algorithm.c

CFILES_BONUS = ./bonus/checker_bonus.c ./bonus/do_sorting_bonus.c ./bonus/sort_ab_bonus.c \
		./bonus/rule1_swap_bonus.c ./bonus/rule2_rotate_bonus.c ./bonus/rule4_push_bonus.c \
		./bonus/rule3_reverse_rotate_bonus.c ./bonus/validate_args_helpers_bonus.c \
		./bonus/sorting_helpers_bonus.c ./bonus/validate_args_bonus.c \
		./bonus/get_next_line_bonus.c
		 
OFILES = $(CFILES:.c=.o)

OFILES_BONUS = $(CFILES_BONUS:.c=.o)

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
RESET=\033[0m

GCC = gcc

AR = ar -rcs

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
		@ $(CC) $(CFLAGS) -c $< -o $@


all: $(NAME) $(B_NAME)

$(NAME): $(OFILES) $(OFILES_BONUS)
		 @ echo "$(YELLOW)push_swap files compiling...."
		 @ $(MAKE) -C ./libft
		 @ $(GCC) $(CFLAGS) $(OFILES) ./libft/libft.a -o $(NAME)
		 @ $(GCC) $(CFLAGS) $(OFILES_BONUS) ./libft/libft.a -o $(B_NAME)
		 @ echo "$(GREEN)Successfully push_swap compiled!"

norm:
	norminette $(CFILES) $(CFILES_BONUS) 

clean:
		@ make -C ./libft fclean
	  @ $(RM) $(OFILES) $(OFILES_BONUS) 
	  @ echo "$(RED)push_swap object files cleaned!$(RESET)"
	  
fclean: clean
	    @ $(RM) $(NAME) $(B_NAME)
		@ echo "$(RED)push_swap executable files cleaned!"

re: fclean all
	@ echo "push_swap RE compiled!$(RESET)"

.PHONY: all clean fclean re