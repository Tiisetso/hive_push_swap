/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 23:04:53 by timurray          #+#    #+#             */
/*   Updated: 2025/09/09 23:05:28 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	radix_sort(t_vec *a_stack, t_vec *b_stack)
{
	unsigned int	max_bits;
	unsigned int	i;
	int				*num;
	size_t			j;
	size_t			a_length;

	i = 0;
	a_length = a_stack->len;
	max_bits = get_max_bits(a_stack);
	while (i < max_bits)
	{
		j = 0;
		while (j < a_length)
		{
			num = ft_vec_get(a_stack, 0);
			if (((*num >> i) & 1u) == 0)
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
