/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:14:06 by wjasmine          #+#    #+#             */
/*   Updated: 2021/11/08 18:44:56 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	is_space(char c)
{
	int	flag;

	flag = 0;
	if (c == '\t' || c == '\n' || c == '\v')
		flag = 1;
	if (c == '\f' || c == '\r' || c == ' ')
		flag = 1;
	return (flag);
}

int	ft_atoi_ps(const char *str, int *nbr)
{
	int					sign;
	unsigned long long	value;

	sign = 1;
	value = 0;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	if (!ft_isdigit(*str))
		return (-1);
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		value = (value * 10) + (*str++ - '0');
		if ((value > INT_MAX && sign == 1)
			|| (value > (unsigned long long)INT_MAX + 1 && sign == -1))
			return (-1);
	}
	if (*str)
		return (-1);
	*nbr = (value * sign);
	return (0);
}
