/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:33:55 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/17 17:53:46 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "parsing.h"

int	main(int ac, char **av)
{
	t_config	config;

	if (parse(ac, av, &config) == -1)
		return (1);
	printf("Number of coders: %d\n", config.nb_coders);
	printf("Time to burnout: %d\n", config.time_burnout);
	printf("Time to compile: %d\n", config.time_compile);
	printf("Time to debug: %d\n", config.time_debug);
	printf("Time to refactor: %d\n", config.time_refactor);
	printf("Nb compiles required: %d\n", config.nb_compiles_required);
	printf("Dongle cooldown: %d\n", config.dongle_cd);
	printf("Scheduler: '%s'\n", config.scheduler);
	return (0);
}
