/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:41:17 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/25 21:58:26 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	compile(t_coder *coder)
{
	if (coder->dongle_1->heap.requests[0].coder->id != coder->id
		|| coder->dongle_2->heap.requests[0].coder->id != coder->id)
		return ;
	coder = get_heap_first(&coder->dongle_1->heap);
	pthread_mutex_lock(&coder->dongle_1->mutex);
	pthread_mutex_lock(&coder->dongle_2->mutex);
	printf("Compiling started by coder %d\n", coder->id);
	usleep(coder->time_compile * 1000);
	coder->required_compilations--;
	coder->status = DEBUGING;
	pthread_mutex_unlock(&coder->dongle_1->mutex);
	pthread_mutex_unlock(&coder->dongle_2->mutex);
}

static t_bool	init_mutexes(t_simulation *simu)
{
	int	i;

	i = 0;
	while (i < simu->nb_coders)
	{
		if (pthread_mutex_init(&simu->dongles[i].mutex, NULL) != 0)
		{
			while (i-- > 0)
				pthread_mutex_destroy(&simu->dongles[i].mutex);
			return (display_error(ERR_MUTEX_INIT, 11, 0), FALSE);
		}
		++i;
	}
	return (TRUE);
}

void	*caca(void *coder)
{
	t_coder	*codeer;

	codeer = coder;
	while (codeer->required_compilations != 0)
	{
		heap_add_back(&codeer->dongle_1->heap, new_request(codeer));
		heap_add_back(&codeer->dongle_2->heap, new_request(codeer));
		codeer->status = COMPILING;
		while (codeer->status == COMPILING)
			compile(codeer);
	}
	return (NULL);
}

static t_bool	init_threads(t_simulation *simu)
{
	int	i;

	i = 0;
	while (i < simu->nb_coders)
	{
		if (pthread_create(&simu->coders[i].thread, NULL, caca,
				&simu->coders[i]) != 0)
		{
			while (i-- > 0)
				pthread_join(simu->coders[i].thread, NULL);
			return (display_error(ERR_THREADS_INIT, 12, 0), FALSE);
		}
		++i;
	}
	return (TRUE);
}

t_bool	run_simulation(t_simulation *simulation)
{
	if (init_mutexes(simulation) == FALSE
		|| init_threads(simulation) == FALSE)
		return (clean_base_objects(simulation), FALSE);
	return (TRUE);
}
