/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:32:46 by wjasmine          #+#    #+#             */
/*   Updated: 2022/03/14 13:32:50 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void    fill_b(t_push_swap *ps)
{
	t_list    *first_a;
	int        med;

	med = ps->arr[ps->size_arr / 2];
	first_a = ps->a;
	while (ps->size_a > 3)
	{
		if (*(int *) first_a->content != ps->arr[0]
			&& *(int *) first_a->content != ps->arr[ps->size_arr - 1]
			&& *(int *) first_a->content != ps->arr[ps->size_arr / 2])
		{
			pb(ps);
			if (*(int *) ps->b->content < med)
				rb(ps);
		}
		else
			ra(ps);
		first_a = ps->a;
	}
}

static int search_in_a(t_push_swap *ps, int value_b)
{
	t_list	*next;
	t_list	*prev;
	int		posn_a;

	posn_a = 0;
	next = ps->a;
	prev = ft_lstlast(ps->a);
	while(next != NULL)
	{
		if(*(int *)prev->content < value_b && *(int *)next->content > value_b)
			return (posn_a);
		next = next->next;
		if (prev->next)
			prev = prev->next;
		else
			prev = ps->a;
		posn_a++;
	}
	return (posn_a);
}

static int	scoring(t_push_swap *ps, t_list *el, int i)
{
	int	up_a;
	int up_b;

	up_b = i;
	up_a = search_in_a(ps, *(int *)el->content);
	el->a_score = - up_a;
	el->b_score = - up_b;
	if(c_ops(el->a_score, el->b_score) >
		c_ops((ps->size_a - up_a), (ps->size_b - up_b)))
	{
		el->a_score = (ps->size_a - up_a);
		el->b_score = (ps->size_b - up_b);
	}
	if (c_ops(el->a_score, el->b_score) > c_ops(-up_a, (ps->size_b - up_b)))
	{
		el->a_score = - up_a;
		el->b_score = (ps->size_b - up_b);
	}
	if (c_ops(el->a_score, el->b_score) > c_ops((ps->size_a - up_a), -up_b))
	{
		el->a_score = (ps->size_a - up_a);
		el->b_score = -up_b;
	}
	return(c_ops(el->a_score, el->b_score));
}

t_list *change_elem(t_push_swap *ps)
{
	int 	min;
	int		i;
	t_list *tmp;
	t_list *current;
	int 	min_ops;

	tmp = ps->b;
	current = ps->b;
	i = 0;
	min = scoring(ps, tmp, i);
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
		min_ops = scoring(ps, tmp, i);
		if (c_ops(current->a_score, current->b_score) < min_ops)
		{
			current = tmp;
			min = min_ops;
		}
	}
	pa(ps);
	return(current);
}

void	sort_big(t_push_swap *ps)
{
	t_list	*tmp;

	fill_b(ps);
	printf("filled stack b\n");// delete before final push
	print_lst(ps->b);
	presort_3(ps);
	while (ps->size_b > 0)
	{
		tmp = change_elem(ps);
		executor(ps, tmp);
	}
	final_sort(ps, ps->a,ps->size_a, ps->arr[0]);
}
