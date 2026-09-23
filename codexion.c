/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:33:55 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/23 16:34:54 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "codexion.h"

int	main(int ac, char **av)
{
	t_config			config;
	t_memory_manager	memory_manager;
	int					i;

	i = 0;
	if (parse(ac, av, &config) == FALSE)
		return (1);
	if (create_objects(&memory_manager, config) == FALSE)
		return (1);
	if (run_simulation(&memory_manager) == FALSE)
		return (1);
	clean_mutexes(&memory_manager);
	clean_threads(&memory_manager);
	clean_base_objects(&memory_manager);
	return (0);
}
