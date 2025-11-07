# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 11:29:36 by vivaz-ca          #+#    #+#              #
#    Updated: 2025/11/07 14:16:06 by vivaz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCDIR = .
OBJDIR = objs

SRC = $(SRCDIR)/philo.c \
      $(SRCDIR)/basic_thread_ops.c \
	  $(SRCDIR)/philo_actions.c \
	  $(SRCDIR)/init.c \
      $(SRCDIR)/utils.c

OBJS = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = cc
# CFLAGS = -Wall -o0 -Wextra -Werror -g -pthread
CFLAGS = -g -o0 -pthread 


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

a: re
	./philo 0003 810 400 0400 002

b: re	
	@./philo 6 410 200 200 1

val: re
	@valgrind --leak-check=full ./philo 6 40 200 500 400

hel: re
	valgrind --tool=helgrind ./philo 2 800 200 200 5

ll: re
	lldb ./philo 6 40 200 500 400

gdb: re
	gdb ./philo 6 40 200 500 400

norm:
	@norminette $(shell find . -type f \( -name "*.c" -o -name "*.h" \)) \
	| awk '/c: Error/ { c++; if (c % 2 == 1) printf "\033[1;35m%s\033[0m\n", $$0; else printf "\033[1;36m%s\033[0m\n", $$0 }'
	@echo "Amount of errors: " && norminette $(shell find . -type f \( -name "*.c" -o -name "*.h" \)) | grep "Error" | wc -l

.PHONY: all clean fclean re a b val
