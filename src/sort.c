/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:34:46 by timurray          #+#    #+#             */
/*   Updated: 2025/09/09 20:32:10 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void radix_sort(t_vec *a_stack, t_vec *b_stack)
{
	unsigned int	max_bits;
	unsigned int	i;
	int				*num;
	size_t			j;
	size_t			a_length;

	i = 0;
	a_length = a_stack->len;
	max_bits = get_max_bits(a_stack);
	while(i < max_bits)
	{
		j = 0;
		while (j < a_length)
		{
			num = ft_vec_get(a_stack, 0);
			if(((*num >> i) & 1u) == 0)
				ft_pb(b_stack, a_stack);
			else
				ft_ra(a_stack);
			j++;
		}
		while (b_stack->len)
			ft_pa(a_stack, b_stack);
		i++;
	}
}

void sort_2(t_vec *a_stack)
{
	ft_ra(a_stack);
}

void sort_3(t_vec *a_stack)
{
	unsigned int *num_0;
	unsigned int *num_1;
	unsigned int *num_2;

	if(!unsorted_check(a_stack))
		return ;
	num_0 = ft_vec_get(a_stack, 0);
	num_1 = ft_vec_get(a_stack, 1);
	num_2 = ft_vec_get(a_stack, 2);
	if (*num_0 > *num_1)
		ft_sa(a_stack);
	if (*num_0 > *num_2)
		ft_rra(a_stack);
	if (*num_1 > *num_2)
		ft_rra(a_stack);
	if (*num_0 > *num_1)
		ft_sa(a_stack); 	
}


void sort_4(t_vec *a_stack, t_vec *b_stack)
{
	size_t min_index;
	size_t half_index;

	get_min_index(a_stack, &min_index, 0);	
	if ((min_index != 0) && (min_index <= (a_stack->len / 2)))
	{
		while(min_index > 0)
		{
			ft_ra(a_stack);
			min_index--;
		}
	}
	else if (min_index != 0)
	{
		half_index = a_stack->len - min_index;
		while(half_index > 0)
		{
			ft_rra(a_stack);
			half_index--;
		}
	}
	ft_pb(b_stack, a_stack);
	sort_3(a_stack);
	ft_pa(a_stack, b_stack);
}

void sort_5(t_vec *a_stack, t_vec *b_stack)
{
	size_t min_index;

	get_min_index(a_stack, &min_index, 0);
	while(min_index > 0)
	{
		ft_ra(a_stack);
		min_index--;
	}
	ft_pb(b_stack, a_stack);
	get_min_index(a_stack, &min_index, 1);
	while(min_index > 0)
	{
		ft_ra(a_stack);
		min_index--;
	}
	ft_pb(b_stack, a_stack);
	sort_3(a_stack);
	ft_pa(a_stack, b_stack);
	ft_pa(a_stack, b_stack);
}
