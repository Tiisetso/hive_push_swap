/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:18:21 by timurray          #+#    #+#             */
/*   Updated: 2025/09/09 20:03:24 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int unsorted_check(t_vec *v)
{
	size_t i;
	int *a;
	int *b;
	int unsorted;

	unsorted = 0;
	i = 0;
	while(i < v->len -1)
	{
		a = ft_vec_get(v, i);
		b = ft_vec_get(v, i + 1);
		if (*a > *b)
		{
			unsorted = 1;
			break;
		}
		i++;
	}
	return (unsorted);
}

int get_min_index(t_vec *v, size_t *min_index, int x)
{
	size_t i;
	int *num;

	i = 0;
	while (i < v->len)
	{
		num = ft_vec_get(v, i);
		if (*num == x)
		{
			*min_index = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int get_min_idx(t_vec *v)
{
	size_t i;
	int min;
	int *num;

	i = 0;
	min = 0;
	while (i < v->len)
	{
		num = ft_vec_get(v, i);
		if (min <= *num)
			min = *num;
		i++;
	}
	return (min);
}