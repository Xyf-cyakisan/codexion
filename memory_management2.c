/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:54:54 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/23 16:08:14 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_management.h"

void	clean_threads(t_memory_manager *mem_man)
{
	int	i;

	i = 0;
	while (i < mem_man->nb_coders)
	{
		pthread_join(mem_man->coders[i].thread, NULL);
		++i;
	}
}
