/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_actions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 13:28:15 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/28 17:15:21 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	compile(t_coder *coder, uint64_t time_start_of_simu)
{
	pthread_mutex_lock(&coder->dongle_1->mutex);
	pthread_mutex_lock(&coder->dongle_2->mutex);
	if (coder->dongle_1->heap.requests[0].coder_id != coder->id
		|| coder->dongle_2->heap.requests[0].coder_id != coder->id)
	{
		pthread_mutex_unlock(&coder->dongle_2->mutex);
		pthread_mutex_unlock(&coder->dongle_1->mutex);
		return ;
	}
	pthread_mutex_lock(&coder->dongle_1->heap.heap_mutex);
	pthread_mutex_lock(&coder->dongle_2->heap.heap_mutex);
	heap_pop(&coder->dongle_1->heap);
	heap_pop(&coder->dongle_2->heap);
	pthread_mutex_unlock(&coder->dongle_2->heap.heap_mutex);
	pthread_mutex_unlock(&coder->dongle_1->heap.heap_mutex);
	coder->last_compile = true_get_time_of_day();
	print_log("is compiling\n", time_start_of_simu, coder);
	usleep(coder->time_compile * 1000);
	coder->required_compilations--;
	coder->status = DEBUGING;
	pthread_mutex_unlock(&coder->dongle_1->mutex);
	pthread_mutex_unlock(&coder->dongle_2->mutex);
}
