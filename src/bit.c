/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:05:04 by timurray          #+#    #+#             */
/*   Updated: 2025/09/09 21:23:30 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

unsigned int	bit_count(unsigned int num)
{
	unsigned int	count;

	count = 0;
	while (num)
	{
		count++;
		num = num >> 1u;
	}
	return (count);
}

unsigned int	get_max_bits(t_vec *v)
{
	return (bit_count(v->len - 1));
}
