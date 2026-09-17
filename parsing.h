/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:13:48 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/17 17:33:58 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "general_utils.h"

typedef struct s_config
{
	const char	*scheduler;
	int			nb_coders;
	int			time_burnout;
	int			time_compile;
	int			time_debug;
	int			time_refactor;
	int			nb_compiles_required;
	int			dongle_cd;
}	t_config;

t_bool	ft_check_number_validity(char *str, int arg_index);
t_bool	ft_check_scheduler(char *str);
int		ft_atoi(const char *nptr, int arg_index);
t_bool	parse(int ac, char **av, t_config *config);

#endif