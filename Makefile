# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 14:33:32 by kkoujan           #+#    #+#              #
#    Updated: 2024/11/14 19:08:45 by kkoujan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
OBJ = ft_printf.o ft_putunbr_base.o ft_putaddress.o

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) rcs $(NAME) $^

makelibft:
	$(MAKE) -C libft

%.o : %.c ft_printf.h makelibft
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
re : fclean all