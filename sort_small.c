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

void    presort_3(t_push_swap *ps)
{
	int    first;
	int    second;
	int    third;

	first = *(int *)(ps->a->content);
	second = *(int *)(ps->a->next->content);
	third = *(int *)(ps->a->next->next->content);
	if (first > second && second < third && first < third) //2 1 3
		sa(ps);
	else if (first > second && second > third && first > third) // 3 2 1
		sa(ps);
	else if (first < second && second > third && first < third) // 1 3 2
		sa(ps);
}

void    sort_3(t_push_swap *ps)
{
	int    first;
	int    second;
	int    third;

	presort_3(ps);
	first = *(int *)(ps->a->content);
	second = *(int *)(ps->a->next->content);
	third = *(int *)(ps->a->next->next->content);
	if (first < second && second > third && first > third)
		rra(ps);
	else if (first > second && second < third && first > third)
		ra(ps);
}

static int    search_min(t_list *lst)
{
	int    steps;
	int    min;
	int    count;

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
void    sort_5(t_push_swap *ps)
{
	int    rot_score;

	while (ps->size_a > 3)
	{
		rot_score = search_min(ps->a);
		if (rot_score < ps->size_a - rot_score)
			while (rot_score--)
				ra(ps);
		else
			while (ps->size_a - rot_score++ > 0)
				rra(ps);
		pb(ps);
	}
	sort_3(ps);
	while (ps->size_a < 5)
		pa(ps);
}