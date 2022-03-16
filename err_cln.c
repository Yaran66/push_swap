/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_cln.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:18:06 by wjasmine          #+#    #+#             */
/*   Updated: 2022/03/16 12:18:12 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	lst_cleaner(t_push_swap *ps)
{
	free(ps->arr);
	ft_lstclear(&ps->a, free);
	ft_lstclear(&ps->b, free);
}
