/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:06:44 by wjasmine          #+#    #+#             */
/*   Updated: 2022/03/16 21:06:53 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

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
		lst_cleaner(ps);
		error("Error\n");
	}
	ps->arr = array;
	ps->size_arr = size_arr;
	ps->size_a = 0;
	ps->size_b = 0;
}

void	ps_performer(t_push_swap *ps, char *line)
{
	if(!ft_strncmp(line, "ra\n", 4))
		ra(ps); // todo verboose, make silent
	else if (!ft_strncmp(line, "rb\n", 4))
		rb(ps);
	else if (!ft_strncmp(line, "rr\n", 4))
		rr(ps);
	else if (!ft_strncmp(line, "rra\n", 5))
		rra(ps);
	else if (!ft_strncmp(line, "rrb\n", 5))
		rrb(ps);
	else if (!ft_strncmp(line, "rrr\n", 5))
		rrr(ps);
	else if (!ft_strncmp(line, "pa\n", 4))
		pa(ps);
	else if (!ft_strncmp(line, "pb\n", 4))
		pb(ps);
	else if (!ft_strncmp(line, "sa\n", 4))
		sa(ps);
	else if (!ft_strncmp(line, "sb\n", 4))
		sb(ps);
	else if (!ft_strncmp(line, "ss\n", 4))
		ss(ps);
	else
		error("Error\n");
}

void	gnl_reader(t_push_swap *ps)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while(line)
	{
		ps_performer(ps, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc == 1)
		return (EXIT_SUCCESS);
	init_t_push_swap(&ps, ft_count_argv(&argv[1]));
	if (parse_argv_to_arr(ps.arr, &argv[1]) == -1)
	{
		lst_cleaner(&ps);
		error("Error\n");
	}
	if (identical_nbr(ps.arr, ps.size_arr) == -1)
	{
		lst_cleaner(&ps);
		error("Error\n");
	}
	fill_lst(&ps);
	//bubble(ps.arr, ps.size_arr);
	gnl_reader(&ps);
	if (sorted(ps.a) == 1 && ps.size_b == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	lst_cleaner(&ps);
	return (0);
}
