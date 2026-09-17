/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:10:34 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/17 17:14:13 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
