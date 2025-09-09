/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:38:48 by timurray          #+#    #+#             */
/*   Updated: 2025/09/09 19:47:01 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

void	error_and_exit(void);

void ft_pa(t_vec *a_stack, t_vec *b_stack);
void ft_pb(t_vec *b_stack, t_vec *a_stack);

void ft_rb(t_vec *b_stack);
void ft_ra(t_vec *a_stack);

void ft_rra(t_vec *a_stack);
void ft_rrb(t_vec *b_stack);

void ft_sa(t_vec *a_stack);
void ft_sb(t_vec *b_stack);

unsigned int bit_count(unsigned int num);
unsigned int get_max_bits(t_vec *v);

void radix_sort(t_vec *a_stack, t_vec *b_stack);
void sort_2(t_vec *a_stack);
void sort_3(t_vec *a_stack);
void sort_4(t_vec *a_stack, t_vec *b_stack);
void sort_5(t_vec *a_stack, t_vec *b_stack);

int unsorted_check(t_vec *v);
int get_min_index(t_vec *v, size_t *min_index, int x);

#endif