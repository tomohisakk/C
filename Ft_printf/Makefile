# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 01:30:26 by tomo              #+#    #+#              #
#    Updated: 2022/06/14 01:59:24 by tomo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c utils.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIB = ar -rcs

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) ./$(NAME)
	$(LIB) $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
