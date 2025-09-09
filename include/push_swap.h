/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:38:48 by timurray          #+#    #+#             */
/*   Updated: 2025/09/09 21:27:24 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

int				is_number(const char *s);
int				check_nums(char **av, int i, t_vec *v, t_vec *a_stack);
void			num_rank(t_vec *v, t_vec *a_stack);
int				duplicate_check(t_vec *v);
void			sort_vec(t_vec *v);
void			error_and_exit(void);
int				unsorted_check(t_vec *v);
int				get_min_index(t_vec *v, size_t *min_index, int x);

unsigned int	bit_count(unsigned int num);
unsigned int	get_max_bits(t_vec *v);

void			ft_pa(t_vec *a_stack, t_vec *b_stack);
void			ft_pb(t_vec *b_stack, t_vec *a_stack);
void			ft_rb(t_vec *b_stack);
void			ft_ra(t_vec *a_stack);
void			ft_rra(t_vec *a_stack);
void			ft_rrb(t_vec *b_stack);
void			ft_sa(t_vec *a_stack);
void			ft_sb(t_vec *b_stack);

void			radix_sort(t_vec *a_stack, t_vec *b_stack);
void			sort_2(t_vec *a_stack);
void			sort_3(t_vec *a_stack);
void			sort_4(t_vec *a_stack, t_vec *b_stack);
void			sort_5(t_vec *a_stack, t_vec *b_stack);

#endif