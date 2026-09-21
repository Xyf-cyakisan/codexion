/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:33:55 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/21 15:07:59 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "codexion.h"

int	main(int ac, char **av)
{
	t_config			config;
	t_memory_manager	memory_manager;

	if (parse(ac, av, &config) == -1)
		return (1);
	if (create_objects(&memory_manager, config) == -1)
		return (1);
	printf("Number of coders: %d\n", config.nb_coders);
	printf("Time to burnout: %d\n", (memory_manager.coders)[0].time_burnout);
	clean(&memory_manager);
	return (0);
}
