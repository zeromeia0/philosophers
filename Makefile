# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 11:29:36 by vivaz-ca          #+#    #+#              #
#    Updated: 2025/10/16 18:52:54 by vvazzs           ###   ########.fr        #
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
# CFLAGS = -Wall -Wextra -Werror -g -pthread
CFLAGS = -g -pthread 


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
	@./philo 3 410 200 200

b: re	
	@./philo 6 410 200 200 3

val: re
	@valgrind --leak-check=full ./philo 6 40 200 500 400

ll: re
	lldb ./philo 6 40 200 500 400

gdb: re
	gdb ./philo 6 40 200 500 400
.PHONY: all clean fclean re a b val
