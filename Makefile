# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 11:29:36 by vivaz-ca          #+#    #+#              #
#    Updated: 2025/10/05 18:19:23 by vvazzs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCDIR = .
OBJDIR = objs
HELPER_DIR = ./helpers

SRC = \
	$(SRCDIR)/philo.c\
	$(HELPER_DIR)/ft_atoi.c

OBJS = $(SRC:../%.c=$(OBJDIR)/%.o)
OBJS := $(OBJS:./%.c=$(OBJDIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread

INCLUDES = -I$(HELPER_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: ../%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o: ./%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME) $(OBJDIR)

re: fclean all

a: re
	@./philo 200 40 200 500

b: re
	@./philo 200 40 200 500 400

val: re
	@valgrind --leak-check=full ./philo 200 40 200 500 400


.PHONY: all clean fclean re a b val