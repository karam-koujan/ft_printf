# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 14:33:32 by kkoujan           #+#    #+#              #
#    Updated: 2024/11/15 09:57:03 by kkoujan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJ = ft_printf.o ft_putunbr_base.o ft_putaddress.o
LIBFT_OBJ = $(LIBFT_DIR)/ft_strlen.o $(LIBFT_DIR)/ft_putnbr_fd.o $(LIBFT_DIR)/ft_putchar_fd.o $(LIBFT_DIR)/ft_putstr_fd.o
all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_OBJ)
	$(AR) rcs $(NAME) $^ $(LIBFT_OBJ)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
