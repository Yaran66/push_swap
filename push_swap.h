/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:22:30 by wjasmine          #+#    #+#             */
/*   Updated: 2022/03/10 20:22:37 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h> // malloc free exit
# include <unistd.h>
# include <limits.h>
# include <stdio.h> // delete prior final push

typedef struct s_list {
	void			*content;
	int				a_score;
	int				b_score;
	struct s_list	*next;
}	t_list;

typedef struct s_push_swap
{
	t_list	*a;
	t_list	*b;
	int		*arr;
	int		size_arr;

	int		size_a;
	int		size_b;
}	t_push_swap;

char	**ft_split(char const *s, char c);
void	init_t_push_swap(t_push_swap *ps, int size_arr);
int		ft_count_argv(char **argv);
int		ft_atoi_ps(const char *str, int *nbr);
int		ft_isdigit(int c);
int		magic_moves(t_push_swap *ps_);
void	fill_lst(t_push_swap *ps);
t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	fill_lst(t_push_swap *ps);
void	bubble(int *arr, int size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	lst_cleaner(t_push_swap *ps);
void	sort_distributor(t_push_swap *ps);
void	sa(t_push_swap *ps);
void    sb(t_push_swap *ps);
void    ss(t_push_swap *ps);
int		ft_lstsize(t_list *lst);

void	print_arr(int *arr, int size);
void	print_lst(t_list *lst);
void	error(char *message);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

#endif //PUSH_SWAP_H
