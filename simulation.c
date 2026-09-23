/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:41:17 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/23 16:45:35 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*tg(void *arg)
{
	static int		i;

	printf("prout (%d)\n", i + 1);
	++i;
	return (arg);
}

static t_bool	init_mutexes(t_memory_manager *mem_man)
{
	int	i;

	i = 0;
	while (i < mem_man->nb_coders)
	{
		if (pthread_mutex_init(&mem_man->dongles[i].mutex, NULL) != 0)
		{
			while (i-- > 0)
				pthread_mutex_destroy(&mem_man->dongles[i].mutex);
			return (display_error(ERR_MUTEX_INIT, 11, 0), FALSE);
		}
		++i;
	}
	return (TRUE);
}

static t_bool	init_threads(t_memory_manager *mem_man)
{
	int	i;

	i = 0;
	while (i < mem_man->nb_coders)
	{
		if (pthread_create(&mem_man->coders[i].thread, NULL, tg,
				NULL) != 0)
		{
			while (i-- > 0)
				pthread_join(mem_man->coders[i].thread, NULL);
			return (display_error(ERR_THREADS_INIT, 12, 0), FALSE);
		}
		++i;
	}
	return (TRUE);
}

t_bool	run_simulation(t_memory_manager *memory_manager)
{
	if (init_mutexes(memory_manager) == FALSE
		|| init_threads(memory_manager) == FALSE)
		return (clean_base_objects(memory_manager), FALSE);
	return (TRUE);
}
