/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:38:48 by timurray          #+#    #+#             */
/*   Updated: 2025/09/09 13:53:42 by timurray         ###   ########.fr       */
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

#endif