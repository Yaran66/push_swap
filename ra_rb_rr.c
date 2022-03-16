/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:46:47 by wjasmine          #+#    #+#             */
/*   Updated: 2022/03/13 19:46:58 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rot_first_to_last(t_list **node)
{
	t_list	*tmp;

	if (!(*node) || !(*node)->next)
		return ;
	tmp = *node;
	*node = (*node)->next;
	ft_lstadd_back(node, tmp);
	tmp->next = NULL;
}

void	ra(t_push_swap *ps)
{
	rot_first_to_last(&ps->a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_push_swap *ps)
{
	rot_first_to_last(&ps->b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_push_swap *ps)
{
	rot_first_to_last(&ps->a);
	rot_first_to_last(&ps->b);
	ft_putstr_fd("rr\n", 1);
}
