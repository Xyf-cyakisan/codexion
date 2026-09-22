/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:52:13 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/22 15:13:53 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "memory_management.h"

t_heap	*new_node(t_coder *coder)
{
	t_heap	*new_node;

	new_node = ft_calloc(1, sizeof(t_heap));
	new_node->coder = coder;
	new_node->next = NULL;
	return (new_node);
}

void	heap_add_back(t_heap *new_node, t_heap *node)
{
	while (node->next != NULL)
		node = node->next;
	node->next = new_node;
}

t_coder	*get_heap_first(t_heap **first_node)
{
	t_coder	*coder;
	t_heap	*leaving_node;

	leaving_node = *first_node;
	coder = (*first_node)->coder;
	*first_node = (*first_node)->next;
	free(leaving_node);
	return (coder);
}
