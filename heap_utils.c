/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:52:12 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/23 16:45:35 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_management.h"
#include "general_utils.h"

t_heap	*new_node(t_coder *coder)
{
	t_heap	*new_node;

	new_node = ft_calloc(1, sizeof(t_heap));
	if (!new_node)
		return (display_error(ERR_EMPTY_NODE_HEAP, 10, 0), NULL);
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
