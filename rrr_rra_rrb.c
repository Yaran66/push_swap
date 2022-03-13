/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_rra_rrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:59:16 by wjasmine          #+#    #+#             */
/*   Updated: 2022/03/13 20:59:23 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	revrot_last_to_first(t_list **node)
{
	t_list	*tmp;

	if(!(*node) || !(*node)->next)
		return ;
	tmp = *node;
	while(tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *node;
	*node = tmp->next;
	tmp->next = NULL;
}

void	rra(t_push_swap *ps)
{
	revrot_last_to_first(&ps->a);
	ft_putstr_fd("rra\n", 1);
}

void    rrb(t_push_swap *ps)
{
	revrot_last_to_first(&ps->b);
	ft_putstr_fd("rrb\n", 1);
}

void    rrr(t_push_swap *ps)
{
	ra(ps);
	rb(ps);
	ft_putstr_fd("rrr\n", 1);
}