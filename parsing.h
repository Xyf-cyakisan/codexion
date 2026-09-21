/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:13:48 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/21 15:00:35 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "general_utils.h"
# include "structures.h"
# include "memory_management.h"

t_bool	ft_check_number_validity(char *str, int arg_index);
t_bool	ft_check_scheduler(char *str);
int		ft_atoi(const char *nptr, int arg_index);
t_bool	parse(int ac, char **av, t_config *config);
t_bool	create_objects(t_memory_manager *memory_manager, t_config config);

#endif