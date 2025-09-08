/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:38:18 by timurray          #+#    #+#             */
/*   Updated: 2025/09/08 20:56:45 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_pa(t_vec *a_stack, t_vec *b_stack)
{
	int *element;

	ft_vec_pop_front(&element, b_stack);
	ft_vec_push_front(a_stack, &element);
	ft_putendl_fd("pa", 1);
}
