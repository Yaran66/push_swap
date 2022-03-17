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

static void	ps_performer(t_push_swap *ps, char *line)
{
	if (!ft_strncmp(line, "ra\n", 4))
		ra(ps, 0);
	else if (!ft_strncmp(line, "rb\n", 4))
		rb(ps, 0);
	else if (!ft_strncmp(line, "rr\n", 4))
		rr(ps, 0);
	else if (!ft_strncmp(line, "rra\n", 5))
		rra(ps, 0);
	else if (!ft_strncmp(line, "rrb\n", 5))
		rrb(ps, 0);
	else if (!ft_strncmp(line, "rrr\n", 5))
		rrr(ps, 0);
	else if (!ft_strncmp(line, "pa\n", 4))
		pa(ps, 0);
	else if (!ft_strncmp(line, "pb\n", 4))
		pb(ps, 0);
	else if (!ft_strncmp(line, "sa\n", 4))
		sa(ps, 0);
	else if (!ft_strncmp(line, "sb\n", 4))
		sb(ps, 0);
	else if (!ft_strncmp(line, "ss\n", 4))
		ss(ps, 0);
	else
		error("Error\n");
}

static void	gnl_reader(t_push_swap *ps)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
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
	gnl_reader(&ps);
	if (sorted(ps.a) == 1 && ps.size_b == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	lst_cleaner(&ps);
	return (0);
}
