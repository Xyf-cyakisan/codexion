/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:24:43 by cyakisan          #+#    #+#             */
/*   Updated: 2026/10/05 17:16:09 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static t_bool	check_finished(t_coder *coder)
{
	t_bool	finished;

	finished = FALSE;
	pthread_mutex_lock(&coder->nb_comp);
	if (coder->required_compilations == 0)
		finished = TRUE;
	pthread_mutex_unlock(&coder->nb_comp);
	return (finished);
}

static void	check_all_deadlines(t_monitor *monitor)
{
	int			i;
	uint64_t	last_compile;

	i = -1;
	while (++i < monitor->nb_coders)
	{
		if (check_finished(&monitor->coders[i]) == TRUE)
			continue ;
		if (*monitor->stop == TRUE)
			break ;
		pthread_mutex_lock(&monitor->coders[i].compile_mutex);
		last_compile = monitor->coders[i].last_compile;
		pthread_mutex_unlock(&monitor->coders[i].compile_mutex);
		if (last_compile == 0)
			last_compile = *monitor->coders[i].time_start_of_simu;
		if (last_compile
			+ monitor->coders[i].time_burnout <= true_get_time_of_day())
		{
			print_log("burned out\n",
				*monitor->coders[i].time_start_of_simu,
				&monitor->coders[i], TRUE);
			return ;
		}
	}
}

void	*monitor(void *arg)
{
	t_monitor	*monitor;

	monitor = arg;
	while (*monitor->simu_started == FALSE)
		usleep(1000);
	while (*monitor->stop == FALSE)
	{
		check_all_deadlines(monitor);
		usleep(1000);
	}
	return (NULL);
}
