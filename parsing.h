/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:13:48 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/15 16:53:54 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "general_utils.h"

void	ft_check_number_validity(char *str, int arg_index);
void	ft_check_scheduler(char *str);
int		ft_atoi(const char *nptr, int arg_index);

#endif