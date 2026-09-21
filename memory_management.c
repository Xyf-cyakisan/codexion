/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:13:16 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/21 15:02:51 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general_utils.h"

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
		return (display_error("Memory allocation failed", 10, 0), NULL);
	tofill = malloc(total_size);
	if (tofill == NULL)
		return (display_error("Memory allocation failed", 10, 0), NULL);
	ft_bzero(tofill, total_size);
	return (tofill);
}

void	clean(t_memory_manager *memory_manager)
{
	free(memory_manager->coders);
	free(memory_manager->dongles);
	memory_manager->coders = NULL;
	memory_manager->dongles = NULL;
}
