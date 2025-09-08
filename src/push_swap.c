/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:56:04 by timurray          #+#    #+#             */
/*   Updated: 2025/09/08 14:03:17 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//TODO: remove
#include <stdio.h>
void print_vec_int(const t_vec *v)
{
    for (size_t i = 0; i < v->len; i++) {
        int val = *(int*)(v->memory + i * v->elem_size);
        printf("[%zu] %d\n", i, val);
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

int check_nums(char **av, int i, t_vec *v)
{
	while(av[i])
	{
		if (!is_number(av[i]))
			return (0);
		if(!check_overflow(av[i]))
			return (0);
		int x = ft_atoi(av[i]);
		if(ft_vec_push(v, &x) == -1)
			return (0);
		i++;
	}
	return (1);
}

int check_single_arg(const char *arg, t_vec *v)
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
	if(!check_nums(args, 0, v))
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

void duplicate_check(t_vec *v)
{
	size_t i;
	int *a;
	int *b;

	i = 0;
	while(i < v->len -1)
	{
		a = ft_vec_get(v, i);
		b = ft_vec_get(v, i + 1);
		if (*a == *b)
		{
			ft_vec_free(v);
			error_and_exit();
		}
		i++;
	}
}

int main(int ac, char **av)
{
	t_vec v;
	int res;
	
	res = ft_vec_new(&v, 0, sizeof(int));
	if (ac < 2)
		exit(1);
	else if (ac == 2)
	{
		if(!check_single_arg(av[1], &v))
		{
			ft_vec_free(&v);
			error_and_exit();
		}
	}
	else
	{
		if(!check_nums(av, 1, &v))
		{
			ft_vec_free(&v);
			error_and_exit();
		}
	}
	sort_vec(&v);
	print_vec_int(&v);
	duplicate_check(&v);
	ft_vec_free(&v);
	return (0);
}

/* 
Tasklist
TODO: check for sorted list

TODO: ./push_swap 1 2 3 4 \0

TODO: Normalising, ie index as values. 

TODO: Count bits
TODO: Find min, find max
TODO: Find a way to get max bits.

TODO: push_swap functions

TODO: algs for 2, 3 , 5.
TODO: push_swap 1?

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