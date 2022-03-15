/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:15:56 by wjasmine          #+#    #+#             */
/*   Updated: 2022/03/10 20:16:15 by wjasmine         ###   ########.fr       */
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

int	ft_count_argv(char **argv)
{
	char	**array;
	int		i;
	int		count_argv;

	count_argv = 0;
	while (*argv)
	{
		if (!ft_strncmp("", *argv, 1) || !ft_strncmp (" ", *argv, 2))
			error("Error\n");
		array = ft_split(*argv++, ' ');
		if (!array)
			error("Error\n");
		i = 0;
		while (array[i])
		{
			count_argv++;
			free(array[i++]);
		}
		free(array);
	}
	return (count_argv);
}

void	init_t_push_swap(t_push_swap *ps, int size_arr)
{
	int	*array;

	ps->a = NULL;
	ps->b = NULL;
	array = (int *)malloc(sizeof(int) * size_arr);
	if (array == NULL)
	{
		free(array);
		error("Error\n");
	}
	ps->arr = array;
	ps->size_arr = size_arr;
	ps->size_a = 0;
	ps->size_b = 0;
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc == 1)
		return (EXIT_SUCCESS);
	init_t_push_swap(&ps, ft_count_argv(&argv[1]));
	if (parse_argv_to_arr(ps.arr, &argv[1]) == -1)
	{
		free(ps.arr);
		free(ps.a);
		error("Error\n");
	}
	if (identical_nbr(ps.arr, ps.size_arr) == -1)
	{
		free(ps.arr);
		free(ps.a);
		error("Error\n");
	}
	if (magic_moves(&ps) == -1)
		error("Error\n");
	return (0);
}
