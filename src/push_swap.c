/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:56:04 by timurray          #+#    #+#             */
/*   Updated: 2025/09/08 19:04:13 by timurray         ###   ########.fr       */
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
}

int check_overflow(const char *s)
{
	long lnum;

	lnum = ft_atol(s);
	if(!(lnum >= INT_MIN && lnum <= INT_MAX))
		return (0);
	return (1);
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
		if(!check_overflow(av[i]))
			return (0);
		x = ft_atoi(av[i]);
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

unsigned int bit_count(unsigned int num)
{
	unsigned int count;

	count = 0;
	while(num)
	{
		count++;
		num = num >> 1u;
	}
	return (count);
}

unsigned int get_max_bits(t_vec *v)
{
	return(bit_count(v->len-1));
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

	print_vec_int(&v); //TODO: remove
	ft_putendl_fd("", 2);
	print_vec_int(&a_stack); //TODO: remove
	

	ft_printf("max rank(i.e. value): %d\n", a_stack.len - 1);
	ft_printf("max bits: %d", get_max_bits(&a_stack));

	ft_vec_free(&v);
	ft_vec_free(&a_stack);
	return (0);
}



/* 
Tasklist
TODO: push_swap functions

TODO: algs for 2, 3, 5. 4?

TODO: Radix with pb, ra, pa.

TODO: 
*/

/* 
Performance criteria
3num 3op
5num 12op
100num 700op
500num 5000op
*/