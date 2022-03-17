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
NAME_B		=	checker

SRCS		=	push_swap.c ft_split.c err_cln.c ft_putchar_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c ft_atoi_ps.c ft_isdigit.c \
				moves.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstlast.c \
				ft_lstnew.c ft_strncmp.c sa_sb_ss.c ft_lstsize.c pa_pb.c ra_rb_rr.c \
				rrr_rra_rrb.c sort_small.c sort_big.c sort_assist.c
SRCS_B		=	ft_split.c err_cln.c ft_putchar_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c ft_atoi_ps.c ft_isdigit.c \
				moves.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstlast.c \
				ft_lstnew.c ft_strncmp.c sa_sb_ss.c ft_lstsize.c pa_pb.c ra_rb_rr.c \
				rrr_rra_rrb.c sort_big.c get_next_line.c checker.c get_next_line_utils.c \
				sort_small.c sort_assist.c checker_asssit.c

HEADER		=	push_swap.h
HEADER_B	=	push_swap.h get_next_line.h

OBJS		= 	${SRCS:%.c=%.o}
OBJS_B		= 	${SRCS_B:%.c=%.o}

T_FILE		=	.bonus

CC			= 	gcc
RM			= 	rm -f

OPTFLAGS 	= 	-O2
CFLAGS		= 	-Wall -Wextra -Werror

.PHONY:			all clean fclean re

all:			${NAME}

${NAME}:		${OBJS}
				${CC} -o ${NAME} ${OBJS}

%.o	:			%.c ${HEADER} ${HEADER_B} Makefile
				${CC} ${CFLAGS} ${OPTFLAGS}	-c $< -o $@

bonus:			${T_FILE}

${T_FILE}:		${OBJS_B}
				${CC} -o ${NAME_B} ${OBJS_B}
				@touch ${T_FILE}

clean:
				${RM} ${OBJS}
				${RM} ${OBJS_B}

fclean:			clean
				${RM} ${NAME}
				${RM} ${NAME_B}

re:				fclean all
