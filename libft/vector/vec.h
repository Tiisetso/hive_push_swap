/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:22:48 by timurray          #+#    #+#             */
/*   Updated: 2025/09/07 19:41:48 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "stdbool.h"
#include "../libft.h"

#include <stdio.h>
#include <assert.h>

typedef struct s_vec
{
	unsigned char *memory;
	size_t elem_size;
	size_t alloc_size; 
	size_t len;
} t_vec;

int vec_new(t_vec *dst, size_t init_len, size_t elem_size);
int vec_resize(t_vec *src, size_t target_len);
void vec_free(t_vec *src);

int	vec_push(t_vec *dst, void *src);
int vec_pop(void *dst, t_vec *src);

void *vec_get(t_vec *src, size_t index);
int vec_from(t_vec *dst, void *src, size_t len, size_t elem_size);

#endif


