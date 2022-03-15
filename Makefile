# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 15:24:34 by wjasmine          #+#    #+#              #
#    Updated: 2022/03/11 15:24:42 by wjasmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	push_swap

SRCS		=	push_swap.c ft_split.c prints.c ft_putchar_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c ft_atoi_ps.c ft_isdigit.c \
				moves.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstlast.c \
				ft_lstnew.c ft_strncmp.c sa_sb_ss.c ft_lstsize.c pa_pb.c ra_rb_rr.c \
				rrr_rra_rrb.c sort_small.c sort_big.c sort_assist.c

HEADER		=	push_swap.h
OBJS		= 	${SRCS:%.c=%.o}

CC			= 	gcc
RM			= 	rm -f

OPTFLAGS 	= 	-O2
CFLAGS		= 	-Wall -Wextra -Werror -I${HEADER}

.PHONY:			all clean fclean re

all:			${NAME}

${NAME}:		${OBJS}
				${CC} -o ${NAME} ${OBJS}

%.o	:			%.c ${HEADER} Makefile
				${CC} ${CFLAGS} ${OPTFLAGS}	-c $< -o $@


clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all
