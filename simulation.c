/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:41:17 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/28 17:32:51 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static t_bool	init_mutexes(t_simulation *simu)
{
	int	i;

	i = 0;
	while (i < simu->nb_coders)
	{
		if (pthread_mutex_init(&simu->dongles[i].mutex, NULL) != 0 || pthread_mutex_init(&simu->dongles[i].heap.heap_mutex, NULL) != 0)
		{
			while (i-- > 0)
			{
				pthread_mutex_destroy(&simu->dongles[i].heap.heap_mutex);
				pthread_mutex_destroy(&simu->dongles[i].mutex);
			}
			return (display_error(ERR_MUTEX_INIT, 11, 0), FALSE);
		}
		++i;
	}
	return (TRUE);
}

static void	*run_single_simulation(void *arg)
{
	t_coder		*coder;
	t_request	request;
	uint64_t	time_start_of_simu;

	coder = arg;
	time_start_of_simu = true_get_time_of_day();
	while (coder->required_compilations != 0)
	{
		pthread_mutex_lock(&coder->dongle_1->heap.heap_mutex);
		pthread_mutex_lock(&coder->dongle_2->heap.heap_mutex);
		request = new_request(coder);
		heap_add_back(&coder->dongle_1->heap, request);
		heap_add_back(&coder->dongle_2->heap, request);
		pthread_mutex_unlock(&coder->dongle_1->heap.heap_mutex);
		pthread_mutex_unlock(&coder->dongle_2->heap.heap_mutex);
		coder->status = COMPILING;
		while (coder->status == COMPILING)
			compile(coder, time_start_of_simu);
		// coder->status = get_next_step(coder->status);
	}
	return (NULL);
}

static t_bool	init_threads(t_simulation *simu)
{
	int	i;

	i = 0;
	while (i < simu->nb_coders)
	{
		if (pthread_create(&simu->coders[i].thread, NULL, run_single_simulation,
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

t_bool	run_whole_simulation(t_simulation *simulation)
{
	if (init_mutexes(simulation) == FALSE
		|| init_threads(simulation) == FALSE)
		return (clean_base_objects(simulation), FALSE);
	return (TRUE);
}
