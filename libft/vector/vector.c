/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:22:14 by timurray          #+#    #+#             */
/*   Updated: 2025/09/07 15:10:13 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

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

int vec_resize(t_vec *src, size_t target_len)
{
	t_vec dst;

	if (!src)
		return (-1);
	else if (!src->memory)
		return (vec_new(&dst, target_len, src->elem_size));
	else if (vec_new(&dst, target_len, src->elem_size) < 0)
		return (-1);
	ft_memcpy(dst.memory, src->memory, src->len * src->elem_size);
	dst.len = src->len;
	vec_free(src);
	*src = dst;
	return (1);
}

int	vec_push(t_vec *dst, void *src)
{
	if (!dst || !src)
		return (-1);
	else if (!dst->memory)
		vec_new(dst, 1, dst->elem_size);
	if (dst->elem_size * dst->len >= dst->alloc_size)
	{
		if(vec_resize(dst, dst->len * 2 ) < 0)
			return (-1);
	}
	ft_memcpy(&dst->memory[dst->elem_size * dst->len], src, dst->elem_size);
	dst->len = dst->len + 1;
	return (1);
}

void *vec_get(t_vec *src, size_t index)
{
	unsigned char *v;

	if (index >= src->len || !src || !src->memory)
		return (NULL);
	v = &src->memory[src->elem_size * index];
	return (v); 
}

int vec_from(t_vec *dst, void *src, size_t len, size_t elem_size)
{
	if (!dst || !src || elem_size == 0)
		return (-1);
	else if (vec_new(dst, len, elem_size) < 0)
		return (-1);
	ft_memcpy(dst->memory, src, dst->alloc_size);
	dst->len = len;
	return (1);
}

int vec_pop(void *dst, t_vec *src)
{
	if (!dst || !src)
		return (-1);
	else if (!src->memory || src->len == 0)
		return (0);
	ft_memcpy(dst, vec_get(src, src->len -1), src->elem_size);
	src->len--;
	return (1);
}

int main(void)
{
    t_vec   t1;
    int     base[] = {1, 2, 3, 4, 5};

    assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
    assert(memcmp(t1.memory, base, sizeof(base)) == 0);
    vec_free(&t1);
    printf("test_vec_from successful!\n");
}
