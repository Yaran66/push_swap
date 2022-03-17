/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:12:54 by wjasmine          #+#    #+#             */
/*   Updated: 2022/03/14 10:13:34 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	presort_3(t_push_swap *ps)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(ps->a->content);
	second = *(int *)(ps->a->next->content);
	third = *(int *)(ps->a->next->next->content);
	if (first > second && second < third && first < third)
		sa(ps, 1);
	else if (first > second && second > third && first > third)
		sa(ps, 1);
	else if (first < second && second > third && first < third)
		sa(ps, 1);
}

void	sort_3(t_push_swap *ps)
{
	int	first;
	int	second;
	int	third;

	presort_3(ps);
	first = *(int *)(ps->a->content);
	second = *(int *)(ps->a->next->content);
	third = *(int *)(ps->a->next->next->content);
	if (first < second && second > third && first > third)
		rra(ps, 1);
	else if (first > second && second < third && first > third)
		ra(ps, 1);
}

static int	search_min(t_list *lst)
{
	int	steps;
	int	min;
	int	count;

	steps = 0;
	count = 0;
	min = *(int *)lst->content;
	while (lst->next != NULL)
	{
		lst = lst->next;
		steps++;
		if (*(int *)lst->content < min)
		{
			min = *(int *)lst->content;
			count = steps;
		}
	}
	return (count);
}

void	sort_5(t_push_swap *ps)
{
	int	rot_score;

	while (ps->size_a > 3)
	{
		rot_score = search_min(ps->a);
		if (rot_score < ps->size_a - rot_score)
			while (rot_score--)
				ra(ps, 1);
		else
			while (ps->size_a - rot_score++ > 0)
				rra(ps, 1);
		pb(ps, 1);
	}
	sort_3(ps);
	while (ps->size_b)
		pa(ps, 1);
}
