/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:18:33 by timurray          #+#    #+#             */
/*   Updated: 2025/09/06 20:40:18 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error_and_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

// int error_and_return(void)
// {
// 	ft_putendl_fd("Error", 2);
// 	return (EXIT_FAILURE);
// }