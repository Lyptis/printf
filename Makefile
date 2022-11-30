# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 11:01:12 by svanmeen          #+#    #+#              #
#    Updated: 2022/11/30 10:08:53 by svanmeen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c	utils.c	ft_printf_hex.c
HSRC	=	.././ft_printf.h
OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a

# ============================================================================ #

GCC		=	gcc
RM		=	rm -f
LIB		=	ar rcs
FLAGS	=	-Wall -Wextra -Werror

.PHONY:		re fclean clean all

.c.o:		Makefile ${HSRC}
			${GCC} ${FLAGS} -I ${HSRC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${LIB} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}
			${RM} ${HSRC}.gch

fclean:		clean
			${RM} ${NAME}

re:			fclean all
