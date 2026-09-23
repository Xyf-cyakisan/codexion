/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:28:49 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/23 15:50:57 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	dongle_lock(t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->mutex);
	dongle->is_available = FALSE;
}

void	dongle_unlock(t_dongle *dongle)
{
	pthread_mutex_unlock(&dongle->mutex);
	dongle->is_available = TRUE;
}

t_bool	is_dongle_available(t_dongle dongle)
{
	return (dongle.is_available);
}
