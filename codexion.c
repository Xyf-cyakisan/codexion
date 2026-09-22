/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:33:55 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/22 15:59:13 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "codexion.h"

int	main(int ac, char **av)
{
	t_config			config;
	t_memory_manager	memory_manager;
	t_heap				*node;
	int					i;

	i = 0;
	if (parse(ac, av, &config) == -1)
		return (1);
	if (create_objects(&memory_manager, config) == -1)
		return (1);
	printf("Number of coders: %d\n", config.nb_coders);
	printf("Time to burnout: %d\n", (memory_manager.coders)[0].time_burnout);
	node = new_node(&memory_manager.coders[0]);
	while (++i < config.nb_coders)
		heap_add_back(new_node(&memory_manager.coders[i]), node);
	while (node != NULL)
		printf("Coder %d\n", get_heap_first(&node)->id);
	start_coders(&memory_manager, config);
	clean(&memory_manager);
	return (0);
}
