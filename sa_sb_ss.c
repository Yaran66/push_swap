/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:52:31 by wjasmine          #+#    #+#             */
/*   Updated: 2022/03/13 13:52:43 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	swap(t_list **node)
{
	t_list	*tmp;

	if (ft_lstsize(*node) < 2)
		return ;
	tmp = *node;
	*node = (*node)->next;
	tmp->next = (*node)->next;
	(*node)->next = tmp;
}

void	sa(t_push_swap *ps, int flag)
{
	swap(&ps->a);
	if (flag)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_push_swap *ps, int flag)
{
	swap(&ps->b);
	if (flag)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_push_swap *ps, int flag)
{
	swap(&ps->a);
	swap(&ps->b);
	if (flag)
		ft_putstr_fd("ss\n", 1);
}
