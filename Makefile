# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 14:33:32 by kkoujan           #+#    #+#              #
#    Updated: 2024/11/13 16:52:08 by kkoujan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror


all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $^

makelibft:
	$(MAKE) -C libft

%.o : %.c libftprintf.h makelibft
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
