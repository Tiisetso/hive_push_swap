/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:56:04 by timurray          #+#    #+#             */
/*   Updated: 2025/09/07 22:19:19 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int check_nums(char **av, int i)
{
	while(av[i])
	{
		if (!is_number(av[i]))
			return (0);
		if(!check_overflow(av[i]))
			return (0);
		// ft_printf("num: %i\n", (int)ft_atol(av[i])); //TODO: Remove
		i++;
	}
	return (1);
}

int check_single_arg(const char *arg)
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
	if(!check_nums(args, 0))
	{
		ft_free_split(args);
		return (0);
	}
	ft_free_split(args);
	return (1);
}

int main (int ac, char **av)
{

	if (ac < 2)
		exit(1);
	else if (ac == 2)
	{
		if(!check_single_arg(av[1]))
			error_and_exit();
	}
	else
	{
		if(!check_nums(av, 1))
			error_and_exit();
	}
	return (0);
}

/* 
TODO: check for duplicates.
TODO: check for sorted list

TODO: character list params?
TODO: Process arguments. First argument is top of stack.


TODO: algs for 3 , 5.

TODO: sort temp stack, bubble?
TODO: Sort and switch to index as values. 

TODO: push_swap functions

TODO: Find a way to get max bits.
TODO: Radix with pb, ra, pa.

TODO: 
*/
/* 
3num 3op
5num 12op
100num 700op
500num 5000op

*/