/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:41:17 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/22 16:02:38 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*tg(void *arg)
{
	static int	i;

	printf("prout (%d)\n", i + 1);
	++i;
	return (arg);
}

void	start_coders(t_memory_manager *mem_man, t_config config)
{
	int	i;

	i = 0;
	while (i < config.nb_coders)
	{
		pthread_create(&mem_man->coders[i].thread, NULL, tg, NULL);
		++i;
	}
	i = 0;
	while (i < config.nb_coders)
	{
		pthread_join(mem_man->coders[i].thread, NULL);
		++i;
	}
}
