/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:10:34 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/23 16:44:14 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "codexion.h"

static void	set_value(int result, t_config *config, int index)
{
	if (index == 1)
		config->nb_coders = result;
	else if (index == 2)
		config->time_burnout = result;
	else if (index == 3)
		config->time_compile = result;
	else if (index == 4)
		config->time_debug = result;
	else if (index == 5)
		config->time_refactor = result;
	else if (index == 6)
		config->nb_compiles_required = result;
	else if (index == 7)
		config->dongle_cd = result;
}

t_bool	additional_checks(t_config *config)
{
	if (config->nb_coders == 0)
		return (display_error(ERR_NB_CODERS, 6, 1), FALSE);
	if (config->time_burnout == 0)
		return (display_error(ERR_TIME_BURNOUT, 7, 2), FALSE);
	if (config->nb_compiles_required == 0)
		return (display_error(ERR_REQUIRED_COMP, 8, 6), FALSE);
	if (config->time_burnout <= config->time_compile
		+ config->time_debug + config->time_refactor)
		return (display_error(ERR_BUR_S, 9, 2), FALSE);
	return (TRUE);
}

t_bool	parse(int ac, char **av, t_config *config)
{
	int			i;
	int			result;

	if (ac == 9)
	{
		i = 1;
		while (i != ac - 1)
		{
			if (ft_check_number_validity(av[i], i) == FALSE)
				return (FALSE);
			result = ft_atoi(av[i], i);
			if (result == FALSE)
				return (FALSE);
			set_value(result, config, i);
			i++;
		}
		if (ft_check_scheduler(av[i]) == FALSE)
			return (FALSE);
		config->scheduler = av[i];
		if (additional_checks(config) == FALSE)
			return (FALSE);
		return (TRUE);
	}
	else
		return (display_error(ERR_NB_ARGS, 1, 0), FALSE);
}

static void	set_values(t_memory_manager *memory_manager,
							t_config config, int nb_dongle)
{
	int	i;

	i = -1;
	while (++i < nb_dongle)
	{
		(memory_manager->dongles)[i].id = i + 1;
		(memory_manager->dongles)[i].last_usage = 0;
		(memory_manager->dongles)[i].is_available = TRUE;
	}
	i = -1;
	while (++i < config.nb_coders)
	{
		(memory_manager->coders)[i].id = i + 1;
		(memory_manager->coders)[i].status = IDLING;
		(memory_manager->coders)[i].last_compile = 0;
		(memory_manager->coders)[i].required_compilations = (config
				.nb_compiles_required);
		(memory_manager->coders)[i].time_compile = config.time_compile;
		(memory_manager->coders)[i].time_burnout = config.time_burnout;
		(memory_manager->coders)[i].time_debug = config.time_debug;
		(memory_manager->coders)[i].time_refactor = config.time_refactor;
		(memory_manager->coders)[i].dongle_1 = &((memory_manager->dongles)[i]);
		(memory_manager->coders)[i].dongle_2 = &((memory_manager->dongles)[
				(i + 1) % config.nb_coders]);
	}
}

t_bool	create_objects(t_memory_manager *memory_manager, t_config config)
{
	int	nb_dongle;

	memory_manager->coders = NULL;
	memory_manager->dongles = NULL;
	memory_manager->heap = NULL;
	memory_manager->nb_coders = config.nb_coders;
	memory_manager->coders = ft_calloc(config.nb_coders, sizeof(t_coder));
	if (!memory_manager->coders)
		return (FALSE);
	nb_dongle = config.nb_coders;
	memory_manager->dongles = ft_calloc(nb_dongle, sizeof(t_dongle));
	if (!memory_manager->dongles)
		return (clean_base_objects(memory_manager), FALSE);
	set_values(memory_manager, config, nb_dongle);
	return (TRUE);
}
