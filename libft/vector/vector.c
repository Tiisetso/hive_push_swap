/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:22:14 by timurray          #+#    #+#             */
/*   Updated: 2025/09/06 19:56:28 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int vec_new(t_vec *dst, size_t init_len, size_t elem_size);

int vec_new(t_vec *dst, size_t init_len, size_t elem_size)
{
	if(!dst || elem_size == 0)
		return (-1);
	dst->alloc_size = init_len * elem_size;
	dst->len = 0;
	dst->elem_size = elem_size;
	if (init_len == 0)
		dst->memory = NULL;
	else
	{
		dst->memory = malloc(dst->alloc_size);
		if(!dst->memory)
			return (-1);
	}
	return (1);
}

void vec_free(t_vec *src)
{
	if(!src || src->alloc_size == 0)
		return ;
	free(src->memory);
	src->memory = NULL;
	src->alloc_size = 0;
	src->elem_size = 0;
	src->len = 0;
}

int main(void)
{
    t_vec t1;

    assert(vec_new(&t1, 0, 0) == -1);
    assert(vec_new(&t1, 0, 1) > 0);
    assert(t1.memory == NULL);
    assert(vec_new(&t1, 1, 0) == -1);
    assert(vec_new(&t1, 10, 1) > 0);
    assert(t1.memory != NULL);
    vec_free(&t1);
    printf("test_vec_new successful!\n");

	assert(vec_new(&t1, 10, 1) > 0);
    vec_free(&t1);
    assert(t1.len == 0);
    assert(t1.alloc_size == 0);
    assert(t1.elem_size == 0);
    assert(t1.memory == NULL);
    printf("test_vec_free successful!\n");
}
