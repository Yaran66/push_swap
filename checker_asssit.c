/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_asssit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:17:55 by wjasmine          #+#    #+#             */
/*   Updated: 2022/03/17 12:17:59 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	identical_nbr(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_argv_to_arr(int *arr, char **argv)
{
	char	**quotes;
	int		i;
	int		flag;
	int		count_argv;

	flag = 0;
	count_argv = 0;
	while (flag != -1 && *argv)
	{
		quotes = ft_split(*argv++, ' ');
		i = 0;
		while (quotes != 0 && quotes[i])
		{
			if (!flag && ft_atoi_ps(quotes[i], &arr[count_argv]) == -1)
				flag = -1;
			count_argv++;
			free(quotes[i++]);
		}
		free(quotes);
	}
	return (flag);
}
