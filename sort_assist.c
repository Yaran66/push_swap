/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_assist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:28:44 by wjasmine          #+#    #+#             */
/*   Updated: 2022/03/15 09:28:51 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	max_abs(int a, int b)
{
	if (abs(a) > abs(b))
		return (abs(a));
	return (abs(b));
}

int	c_ops(int a, int b)
{
	if(a * b > 0)
		return(max_abs(a, b));
	else
		return(abs(a) + abs(b));
}

void	executor(t_push_swap *ps, t_list *el)
{
	while (el->a_score > 0 && el->b_score > 0 && el->a_score-- &&
	el->b_score-- )
		rrr(ps);
	while (el->a_score < 0 && el->b_score < 0 && el->a_score++ &&
		   el->b_score++ )
		rr(ps);
	while (el->a_score > 0 && el->a_score--)
		rra(ps);
	while (el->a_score < 0 && el->a_score++)
		ra(ps);
	while (el->b_score > 0 && el->b_score--)
		rrb(ps);
	while (el->b_score < 0 && el->b_score++)
		rb(ps);
	pa(ps);
}

void	final_sort(t_push_swap *ps, t_list *lst,int size_a, int min)
{
	int i;

	i = 0;
	while(lst && *(int *)lst->content != min )
	{
		i++;
		lst = lst->next;
	}
	if (i < (size_a - i))
		while(i--)
			ra(ps);
	else
	{
		i = size_a - i;
		while(i--)
			rra(ps);
	}
}