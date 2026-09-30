/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:14:03 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/30 16:39:14 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include "general_utils.h"
# include <pthread.h>
# include <stdint.h>
# include "structures.h"
# include <unistd.h>
# include "memory_management.h"

t_request	new_request(t_coder *coder);
void		heap_add_back(t_heap *heap, t_request request);
void		heap_pop(t_heap *heap);
t_status	get_next_step(t_status current_step);
void		print_log(char *log, uint64_t time_start_of_simu, t_coder *coder);
t_bool		check_dongles_cooldowns(t_coder *coder);
void		update_dongle_cooldown(t_coder *coder);
t_bool		check_if_coder_can_compile(t_coder *coder);
void		compile(t_coder *coder, uint64_t time_start_of_simu);
void		debug(t_coder *coder, uint64_t time_start_of_simu);
void		refactor(t_coder *coder, uint64_t time_start_of_simu);
void		coder_act(t_coder *coder, uint64_t time_start_of_simu,
			int required_comps_beg, t_request request);
t_bool		run_whole_simulation(t_simulation *simulation);

#endif
