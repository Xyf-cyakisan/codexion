/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 13:53:53 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/28 15:06:42 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_status	get_next_step(t_status current_step)
{
	if (current_step == IDLING)
		return (COMPILING);
	else if (current_step == COMPILING)
		return (DEBUGING);
	else if (current_step == DEBUGING)
		return (REFACTORING);
	else
		return (IDLING);
}

void	print_log(char *log, uint64_t time_start_of_simu, t_coder *coder)
{
	pthread_mutex_lock(coder->log_mutex);
	printf("%lld ", (long long int)(true_get_time_of_day()
			- time_start_of_simu));
	printf("%d ", coder->id);
	printf("%s", log);
	pthread_mutex_unlock(coder->log_mutex);
}
