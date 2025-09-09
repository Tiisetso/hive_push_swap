/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:34:46 by timurray          #+#    #+#             */
/*   Updated: 2025/09/09 16:41:36 by timurray         ###   ########.fr       */
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
	unsigned int *num_1;
	unsigned int *num_2;

	num_1 = ft_vec_get(a_stack, 0);
	num_2 = ft_vec_get(a_stack, 1);
	if ((*num_1 == 2) && (*num_2 ==  1))
	{
		ft_ra(a_stack);
		ft_sa(a_stack);
	}
	else if ((*num_1 == 2) && (*num_2 == 0))
		ft_ra(a_stack);
	else if ((*num_1 == 1) && (*num_2 == 0))
		ft_sa(a_stack);
	else if ((*num_1 == 1) && (*num_2 == 2))
		ft_rra(a_stack);
	else
	{
		ft_sa(a_stack);
		ft_ra(a_stack);
	}
}
/* 
1
2
3

3 2 1 
2 1 2
1 3 3

3 1
1 2
2 3

2 1
1 2
3 3

2 1
3 2	
1 3

1 3 1
3 1 2
2 2 3

*/