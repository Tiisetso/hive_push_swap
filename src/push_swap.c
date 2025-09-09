/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:56:04 by timurray          #+#    #+#             */
/*   Updated: 2025/09/09 16:41:13 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void print_vec_int(t_vec *v) //TODO: remove
{
	size_t i;
	int *num;

	i = 0;
	while(i < v->len)
	{
		num = ft_vec_get(v, i);
		ft_printf("[%i] %i\n",(int)i, *num);
		i++;
	}
	ft_putendl_fd("", 1);
}

int is_number(const char *s)
{
    int i;

	i = 0;
    if (!s || !s[0])
        return (0);
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (!s[i])
        return (0);
    while (s[i])
    {
        if (!ft_isdigit(s[i]))
            return (0);
        i++;
    }
	return (1);
}


int check_nums(char **av, int i, t_vec *v, t_vec *a_stack)
{
	int x;

	while(av[i])
	{
		if (!is_number(av[i]))
			return (0);
		if (!ft_atoi_check(av[i], &x))
			return (0);
		if(ft_vec_push(v, &x) == -1)
			return (0);
		if(ft_vec_push(a_stack, &x) == -1)
			return (0);
		i++;
	}
	return (1);
}

int check_single_arg(const char *arg, t_vec *v, t_vec *a_stack)
{
	char **args;
	int i;

	i = 0;
	args = ft_split(arg, ' ');
	if(!args)
		return (0);
	if(!args[0])
	{
		ft_free_split(args);
		return (0);
	}
	if(!check_nums(args, 0, v, a_stack))
	{
		ft_free_split(args);
		return (0);
	}
	ft_free_split(args);
	return (1);
}

void sort_vec(t_vec *v)
{
	size_t i;
	size_t j;
	int *a;
	int *b;
	int temp;

	i = 0;
	while(i < v->len - 1)
	{
		j = i + 1;
		while(j < v->len)
		{
			a = ft_vec_get(v, i);
			b = ft_vec_get(v, j);
			if(*a > *b)
			{
				temp = *a;
				*a = *b;
				*b = temp;
			}
			j++;
		}
		i++;
	}
}

int duplicate_check(t_vec *v)
{
	size_t i;
	int *a;
	int *b;
	int duplicates;

	i = 0;
	duplicates = 0;
	while(i < v->len -1)
	{
		a = ft_vec_get(v, i);
		b = ft_vec_get(v, i + 1);
		if (*a == *b)
			duplicates = 1;
		i++;
	}
	return (duplicates);
}

int unsorted_check(t_vec *v)
{
	size_t i;
	int *a;
	int *b;
	int unsorted;

	unsorted = 0;
	i = 0;
	while(i < v->len -1)
	{
		a = ft_vec_get(v, i);
		b = ft_vec_get(v, i + 1);
		if (*a > *b)
		{
			unsorted = 1;
			break;
		}
		i++;
	}
	return (unsorted);
}

void input_check(int ac, char **av, t_vec *v, t_vec *a_stack)
{
	if (ac < 2)
		exit(1);
	else if (ac == 2)
	{
		if(!check_single_arg(av[1], v, a_stack))
		{
			ft_vec_free(v);
			ft_vec_free(a_stack);
			error_and_exit();
		}
	}
	else
	{
		if(!check_nums(av, 1, v, a_stack))
		{
			ft_vec_free(v);
			ft_vec_free(a_stack);
			error_and_exit();
		}
	}
}

void list_check(t_vec *v, t_vec *a_stack)
{
	if(!unsorted_check(a_stack))
	{
		if(duplicate_check(v))
		{
			ft_vec_free(v);
			ft_vec_free(a_stack);
			error_and_exit();
		}
		ft_vec_free(v);
		ft_vec_free(a_stack);
		exit(0);
	}
	else
	{
		if(duplicate_check(v))
		{
			ft_vec_free(v);
			ft_vec_free(a_stack);
			error_and_exit();
		}
	}
}

void num_rank(t_vec *v, t_vec *a_stack)
{
	size_t i;
	size_t rank;
	int *v_num;
	int *a_num;

	i = 0;
	while (i < a_stack->len)
	{
		rank = 0;
		a_num = ft_vec_get(a_stack, i);
		while (rank < v->len)
		{
			v_num = ft_vec_get(v, rank);
			if (*a_num == *v_num)
				*a_num = rank;
			rank++;
		}
		i++;
	}
}


int main(int ac, char **av)
{
	t_vec v;
	t_vec a_stack;

	if(!(ft_vec_new(&v, 0, sizeof(int)) > 0))
		exit(1);
	if(!(ft_vec_new(&a_stack, 0, sizeof(int)) > 0))
	{
		ft_vec_free(&v);
		exit(1);
	}
	input_check(ac, av, &v, &a_stack);
	sort_vec(&v);
	list_check(&v, &a_stack);
	num_rank(&v, &a_stack);
	ft_vec_free(&v);


	t_vec b_stack;
	ft_vec_new(&b_stack, 0, sizeof(int));

	if(a_stack.len == 2)
		sort_2(&a_stack);
	else if(a_stack.len == 3)
		sort_3(&a_stack);
	else
		radix_sort(&a_stack, &b_stack);

	ft_vec_free(&b_stack);
	ft_vec_free(&a_stack);
	return (0);
}

/* 
Tasklist
TODO: 2 nums
TODO: 3 nums
TODO: 5 nums
TODO: 4 nums

TODO:ss, rr, rrr

TODO: return value/error checking swap functions?
*/

/* 
Performance criteria
3num	3op
5num	12op
*/


/* 	
//example ops check
print_vec_int(&a_stack);
print_vec_int(&b_stack);

ft_sa(&a_stack);
print_vec_int(&a_stack);
print_vec_int(&b_stack);

ft_pb(&b_stack, &a_stack);
ft_pb(&b_stack, &a_stack);
ft_pb(&b_stack, &a_stack);
print_vec_int(&a_stack);
print_vec_int(&b_stack);

ft_ra(&a_stack);
ft_rb(&b_stack);
print_vec_int(&a_stack);
print_vec_int(&b_stack);

ft_rra(&a_stack);
ft_rrb(&b_stack);
print_vec_int(&a_stack);
print_vec_int(&b_stack);

ft_sa(&a_stack);
print_vec_int(&a_stack);
print_vec_int(&b_stack);

ft_pa(&a_stack, &b_stack);
ft_pa(&a_stack, &b_stack);
ft_pa(&a_stack, &b_stack);
print_vec_int(&a_stack);
print_vec_int(&b_stack);
*/
