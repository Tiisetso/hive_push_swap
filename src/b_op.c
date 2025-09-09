/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:23:46 by timurray          #+#    #+#             */
/*   Updated: 2025/09/09 13:59:36 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_pb(t_vec *b_stack, t_vec *a_stack)
{
	int *element;

	if(a_stack->len < 1)
		return ;
	ft_vec_pop_front(&element, a_stack);
	ft_vec_push_front(b_stack, &element);
	ft_putendl_fd("pb", 1);
}

void ft_rb(t_vec *b_stack)
{
	int *elem;

	ft_vec_pop_front(&elem, b_stack);
	ft_vec_push(b_stack, &elem);
	ft_putendl_fd("rb", 1);
}

void ft_rrb(t_vec *b_stack)
{
	int *elem;

	ft_vec_pop(&elem, b_stack);
	ft_vec_push_front(b_stack, &elem);
	ft_putendl_fd("rrb", 1);
}

void ft_sb(t_vec *b_stack)
{
	int *elem_1;
	int *elem_2;

	if (b_stack->len <= 1)
		return ;
	ft_vec_pop_front(&elem_1, b_stack);
	ft_vec_pop_front(&elem_2, b_stack);
	ft_vec_push_front(b_stack, &elem_1);
	ft_vec_push_front(b_stack, &elem_2);
	ft_putendl_fd("sb", 1);
}