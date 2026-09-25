/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:52:12 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/25 21:55:02 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_management.h"
#include "general_utils.h"

t_request	new_request(t_coder *coder)
{
	t_request	request;

	request.coder = coder;
	request.last_compile = coder->last_compile;
	return (request);
}

void	heap_add_back(t_heap *heap, t_request request)
{
	t_request	temp_request;

	heap->requests[heap->size] = request;
	++heap->size;
	if (!strcmp(request.coder->scheduler, "edf") && heap->size == 2)
	{
		if (heap->requests[0].last_compile > heap->requests[1].last_compile)
		{
			temp_request = heap->requests[0];
			heap->requests[0] = heap->requests[1];
			heap->requests[1] = temp_request;
		}
	}
}

t_coder	*get_heap_first(t_heap *heap)
{
	t_coder	*temp_coder;

	--heap->size;
	temp_coder = heap->requests[0].coder;
	if (heap->requests[1].coder)
		heap->requests[0].coder = heap->requests[1].coder;
	return (temp_coder);
}
