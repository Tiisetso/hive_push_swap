/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:56:04 by timurray          #+#    #+#             */
/*   Updated: 2025/09/09 21:21:40 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_single_arg(const char *arg, t_vec *v, t_vec *a_stack)
{
	char	**args;
	int		i;

	i = 0;
	args = ft_split(arg, ' ');
	if (!args)
		return (0);
	if (!args[0])
	{
		ft_free_split(args);
		return (0);
	}
	if (!check_nums(args, 0, v, a_stack))
	{
		ft_free_split(args);
		return (0);
	}
	ft_free_split(args);
	return (1);
}

static void	input_check(int ac, char **av, t_vec *v, t_vec *a_stack)
{
	if (ac < 2)
		exit(1);
	else if (ac == 2)
	{
		if (!check_single_arg(av[1], v, a_stack))
		{
			ft_vec_free(v);
			ft_vec_free(a_stack);
			error_and_exit();
		}
	}
	else
	{
		if (!check_nums(av, 1, v, a_stack))
		{
			ft_vec_free(v);
			ft_vec_free(a_stack);
			error_and_exit();
		}
	}
}

static void	list_check(t_vec *v, t_vec *a_stack)
{
	if (!unsorted_check(a_stack))
	{
		if (duplicate_check(v))
		{
			ft_vec_free(v);
			ft_vec_free(a_stack);
			error_and_exit();
		}
		ft_vec_free(v);
		ft_vec_free(a_stack);
		exit(0);
	}
	else
	{
		if (duplicate_check(v))
		{
			ft_vec_free(v);
			ft_vec_free(a_stack);
			error_and_exit();
		}
	}
}

static void	go_go_algorithm(t_vec *a_stack, t_vec *b_stack)
{
	size_t	len;

	len = a_stack->len;
	if (len == 2)
		sort_2(a_stack);
	else if (len == 3)
		sort_3(a_stack);
	else if (len == 4)
		sort_4(a_stack, b_stack);
	else if (len == 5)
		sort_5(a_stack, b_stack);
	else
		radix_sort(a_stack, b_stack);
}

int	main(int ac, char **av)
{
	t_vec	v;
	t_vec	a_stack;
	t_vec	b_stack;

	if (!(ft_vec_new(&v, 0, sizeof(int)) > 0))
		exit(1);
	if (!(ft_vec_new(&a_stack, 0, sizeof(int)) > 0))
		exit(1);
	if (!(ft_vec_new(&b_stack, 0, sizeof(int)) > 0))
		exit(1);
	input_check(ac, av, &v, &a_stack);
	sort_vec(&v);
	list_check(&v, &a_stack);
	num_rank(&v, &a_stack);
	go_go_algorithm(&a_stack, &b_stack);
	ft_vec_free(&v);
	ft_vec_free(&b_stack);
	ft_vec_free(&a_stack);
	return (0);
}
