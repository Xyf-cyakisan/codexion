/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:07:05 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/21 14:32:02 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdint.h>

typedef int	t_bool;

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

typedef int	t_status;

typedef struct s_dongle
{
	uint64_t	last_usage;
	int			id;
}	t_dongle;

typedef struct s_coder
{
	int			id;
	t_status	status;
	uint64_t	last_compile;
	int			required_compilations;
	int			time_compile;
	int			time_burnout;
	int			time_debug;
	int			time_refactor;
	t_dongle	dongle_1;
	t_dongle	dongle_2;
}	t_coder;

typedef struct s_memory_manager
{
	t_coder		*coders;
	t_dongle	*dongles;
	int			nb_coders;
}	t_memory_manager;


#endif