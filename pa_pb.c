/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:05:45 by wjasmine          #+#    #+#             */
/*   Updated: 2022/03/13 18:05:50 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	tmp = *src;
	if (src)
	{
		*src = (*src)->next;
		tmp->next = NULL;
		ft_lstadd_front(dest, tmp);
	}
}

void	pa(t_push_swap *ps, int flag)
{
	if (ps->b)
	{
		push(&ps->b, &ps->a);
		ps->size_a++;
		ps->size_b--;
	}
	if (flag)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_push_swap *ps, int flag)
{
	if (ps->a)
	{
		push(&ps->a, &ps->b);
		ps->size_a--;
		ps->size_b++;
	}
	if (flag)
		ft_putstr_fd("pb\n", 1);
}
