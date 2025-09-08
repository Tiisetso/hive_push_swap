/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:23:46 by timurray          #+#    #+#             */
/*   Updated: 2025/09/08 20:55:36 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_pb(t_vec *b_stack, t_vec *a_stack)
{
	int *element;

	ft_vec_pop_front(&element, a_stack);
	ft_vec_push_front(b_stack, &element);
	ft_putendl_fd("pb", 1);
}