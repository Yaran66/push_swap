cmake_minimum_required(VERSION 3.19)
project(push_swap_ps C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap_ps
        ft_split.c
        err_cln.c
        moves.c
        ft_putchar_fd.c
        ft_putnbr_fd.c
        ft_putstr_fd.c
        ft_strlen.c
        ft_atoi_ps.c
        ft_isdigit.c
        ft_lstadd_back.c
        ft_lstadd_front.c
        ft_lstclear.c
        ft_lstlast.c
        ft_lstnew.c
        ft_strncmp.c
        ft_lstsize.c
        sa_sb_ss.c
        pa_pb.c
        ra_rb_rr.c
        rrr_rra_rrb.c
        sort_big.c
        sort_small.c
        sort_assist.c
        get_next_line.c
        get_next_line_utils.c
        checker.c )
