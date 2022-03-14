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

static	int	abs_(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static int	max_abs(int a, int b)
{
	if (abs_(a) > abs_(b))
		return (abs_(a));
	return (abs_(b));
}

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

static int	scoring(t_push_swap *ps, t_list *tmp, int i)
{


}

static int	count_ops(int a, int b)
{
	if(1)
	{
		
	}
//	if ((lst->a_score * lst->b_score) >= 0) //  ">" and "=" is this OK, or
//		// only ">" ?
//		return(abs_(lst->a_score) + abs_(lst->b_score));
//	else
//		return (max_abs(lst->a_score, lst->b_score))
}

t_list *change_elem(t_push_swap *ps)
{
	int 	min;
	int 	i;
	t_list	*tmp;
	t_list	*current;

	tmp = ps->b;
	current = ps->b;
	i = 0;
	min = scoring(ps, tmp, i);
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
		if (count_ops(current->a_score, current->b_score) < scoring(ps, tmp, i))
		{

		}
//		min = scoring(ps, tmp, i)
	}

}

void	sort_big(t_push_swap *ps)
{
	fill_b(ps);
	printf("filled stack b\n");// delete before final push
	print_lst(ps->b);
	presort_3(ps);
	change_elem(ps);
//	scoring
//	search_in_a
//	count_ops
//	best_list(tmp_current)
//	performer(executor, 6while);
//	final_sort(found )
}
