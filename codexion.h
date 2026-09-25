/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:14:03 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/25 22:03:37 by cyakisan         ###   ########.fr       */
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

# define IDLING 0
# define COMPILING 1
# define DEBUGING 2
# define REFACTORING 3

t_request	new_request(t_coder *coder);
void		heap_add_back(t_heap *heap, t_request request);
t_coder		*get_heap_first(t_heap *heap);
t_bool		run_simulation(t_simulation *simulation);

#endif
