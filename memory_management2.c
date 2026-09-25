/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:54:54 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/25 16:05:02 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_management.h"

void	clean_threads(t_simulation *simu)
{
	int	i;

	i = 0;
	while (i < simu->nb_coders)
	{
		pthread_join(simu->coders[i].thread, NULL);
		++i;
	}
}
