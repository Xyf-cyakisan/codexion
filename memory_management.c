/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:12:16 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/23 16:46:59 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general_utils.h"
#include "memory_management.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*temp;

	i = 0;
	temp = s;
	while (i < n)
	{
		temp[i] = '\0';
		++i;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*tofill;

	total_size = nmemb * size;
	if (size && nmemb && nmemb > (size_t)-1 / size)
		return (display_error("Memory allocation failed", 9, 0), NULL);
	tofill = malloc(total_size);
	if (tofill == NULL)
		return (display_error("Memory allocation failed", 9, 0), NULL);
	ft_bzero(tofill, total_size);
	return (tofill);
}

void	clean_base_objects(t_memory_manager *memory_manager)
{
	free(memory_manager->coders);
	free(memory_manager->dongles);
	memory_manager->coders = NULL;
	memory_manager->dongles = NULL;
}

void	clean_heap(t_memory_manager *mem_man)
{
	t_heap	*next;

	if (!mem_man->heap)
		return ;
	next = mem_man->heap->next;
	while (mem_man->heap != NULL)
	{
		next = mem_man->heap->next;
		free(mem_man->heap);
		mem_man->heap = next;
	}
	mem_man->heap = NULL;
}

void	clean_mutexes(t_memory_manager *mem_man)
{
	int	i;

	i = 0;
	while (i < mem_man->nb_coders)
	{
		pthread_mutex_destroy(&mem_man->dongles[i].mutex);
		++i;
	}
}
