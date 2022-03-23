/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:49:07 by wjasmine          #+#    #+#             */
/*   Updated: 2021/11/08 19:24:42 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;

	i = n;
	if (i < 0)
	{
		ft_putchar_fd ('-', fd);
		i = i * (-1);
	}
	if (i < 10)
		ft_putchar_fd ((char)('0' + i), fd);
	if (i > 9)
	{
		ft_putnbr_fd (i / 10, fd);
		ft_putchar_fd ((char)('0' + (i % 10)), fd);
	}
}
