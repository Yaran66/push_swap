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

int	ft_atoi_ps(const char *str, int *nbr)
{
	int		sign;
	size_t	value;

	sign = 1;
	value = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' ||
	*str == '\r' || *str == ' ')
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
