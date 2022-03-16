/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:55:13 by wjasmine          #+#    #+#             */
/*   Updated: 2022/03/12 15:55:21 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_distributor(t_push_swap *ps)
{
	if (ps->size_a == 2)
		sa(ps);
	else if (ps->size_a == 3)
		sort_3(ps);
	else if (ps->size_a < 6)
		sort_5(ps);
	else
		sort_big(ps);
}

void	fill_lst(t_push_swap *ps)
{
	t_list	*tmplst;
	int		*tmp_nbr;
	int		i;

	i = 0;
	while (i < ps->size_arr)
	{
		tmp_nbr = (int *)malloc(sizeof(int) * 1);
		if (tmp_nbr)
		{
			*tmp_nbr = ps->arr[i];
			tmplst = ft_lstnew(tmp_nbr);
		}
		if (!tmplst || !tmp_nbr)
		{
			free(tmp_nbr);
			free(tmplst);
			ft_lstclear(&ps->a, free);
			error("Error\n");
		}
		ft_lstadd_back(&ps->a, tmplst);
		i++;
	}
	ps->size_a = ps->size_arr;
}

int	sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (*(int *)(lst->content) > *(int *)(lst->next->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	bubble(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	magic_moves(t_push_swap *ps_)
{
	fill_lst(ps_);
	if (sorted(ps_->a))
	{
		lst_cleaner(ps_);
		return (0);
	}
	bubble(ps_->arr, ps_->size_arr);
	sort_distributor(ps_);
	return (0);
}
