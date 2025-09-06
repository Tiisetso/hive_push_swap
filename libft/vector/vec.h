/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:22:48 by timurray          #+#    #+#             */
/*   Updated: 2025/09/06 19:42:49 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "stdbool.h"

#include <stdio.h>
#include <assert.h>

typedef struct s_vec
{
	unsigned char *memory;
	size_t elem_size;
	size_t alloc_size;
	size_t len;
} t_vec;


#endif