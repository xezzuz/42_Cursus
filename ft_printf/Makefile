# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 20:13:46 by nazouz            #+#    #+#              #
#    Updated: 2023/11/03 20:13:46 by nazouz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	libftprintf.a

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

INCLUDES		=	ft_printf.h

AR				=	ar crs

RM				=	rm -rf

SRCS			=	\
					./ft_printf.c \
					./ft_print_add.c \
					./ft_printhex.c \
					./ft_printu.c \
					./ft_putchar.c \
					./ft_putnbr.c \
					./ft_putstr.c

OBJS			=	$(SRCS:.c=.o)

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
RESET = \033[0m

all : $(NAME)

%.o : %.c $(INCLUDES)
	@ $(CC) -c $(CFLAGS) $< -o $@

$(NAME) : $(OBJS)
	@ $(AR) $(NAME) $(OBJS)
	@ printf "$(GREEN)=============================================================\n"
	@ printf "            $(NAME) has been created succesfully.\n"
	@ printf "=============================================================$(RESET)\n"

clean :
	@ $(RM) $(OBJS)
	@ printf "$(RED)=============================================================\n"
	@ printf "            All object files have been destroyed.\n"
	@ printf "=============================================================$(RESET)\n"

fclean : clean
	@ $(RM) $(NAME)
	@ printf "$(RED)=============================================================\n"
	@ printf "          All executable files have been destroyed.\n"
	@ printf "=============================================================$(RESET)\n"

re : fclean all

.PHONY : all clean fclean re