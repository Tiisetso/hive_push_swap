/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:38:18 by timurray          #+#    #+#             */
/*   Updated: 2025/09/09 13:59:29 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_pa(t_vec *a_stack, t_vec *b_stack)
{
	int *element;

	if(b_stack->len < 1)
		return ;
	ft_vec_pop_front(&element, b_stack);
	ft_vec_push_front(a_stack, &element);
	ft_putendl_fd("pa", 1);
}

void ft_ra(t_vec *a_stack)
{
	int *elem;

	ft_vec_pop_front(&elem, a_stack);
	ft_vec_push(a_stack, &elem);
	ft_putendl_fd("ra", 1);
}

void ft_rra(t_vec *a_stack)
{
	int *elem;

	ft_vec_pop(&elem, a_stack);
	ft_vec_push_front(a_stack, &elem);
	ft_putendl_fd("rra", 1);
}

void ft_sa(t_vec *a_stack)
{
	int *elem_1;
	int *elem_2;

	if (a_stack->len <= 1)
		return ;
	ft_vec_pop_front(&elem_1, a_stack);
	ft_vec_pop_front(&elem_2, a_stack);
	ft_vec_push_front(a_stack, &elem_1);
	ft_vec_push_front(a_stack, &elem_2);
	ft_putendl_fd("sa", 1);
}