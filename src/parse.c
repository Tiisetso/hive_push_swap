/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:36:20 by timurray          #+#    #+#             */
/*   Updated: 2025/09/09 21:15:02 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_number(const char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_nums(char **av, int i, t_vec *v, t_vec *a_stack)
{
	int	x;

	while (av[i])
	{
		if (!is_number(av[i]))
			return (0);
		if (!ft_atoi_check(av[i], &x))
			return (0);
		if (ft_vec_push(v, &x) == -1)
			return (0);
		if (ft_vec_push(a_stack, &x) == -1)
			return (0);
		i++;
	}
	return (1);
}

void	num_rank(t_vec *v, t_vec *a_stack)
{
	size_t	i;
	size_t	rank;
	int		*v_num;
	int		*a_num;

	i = 0;
	while (i < a_stack->len)
	{
		rank = 0;
		a_num = (int *)ft_vec_get(a_stack, i);
		while (rank < v->len)
		{
			v_num = (int *)ft_vec_get(v, rank);
			if (*a_num == *v_num)
			{
				*a_num = (int)rank;
				break ;
			}
			rank++;
		}
		i++;
	}
}

int	duplicate_check(t_vec *v)
{
	size_t	i;
	int		*a;
	int		*b;
	int		duplicates;

	i = 0;
	duplicates = 0;
	while (i < v->len - 1)
	{
		a = ft_vec_get(v, i);
		b = ft_vec_get(v, i + 1);
		if (*a == *b)
			duplicates = 1;
		i++;
	}
	return (duplicates);
}

void	sort_vec(t_vec *v)
{
	size_t	i;
	size_t	j;
	int		*a;
	int		*b;
	int		temp;

	i = 0;
	while (i < v->len - 1)
	{
		j = i + 1;
		while (j < v->len)
		{
			a = ft_vec_get(v, i);
			b = ft_vec_get(v, j);
			if (*a > *b)
			{
				temp = *a;
				*a = *b;
				*b = temp;
			}
			j++;
		}
		i++;
	}
}
