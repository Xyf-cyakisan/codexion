/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:45:27 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/15 16:56:42 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_UTILS_H
# define GENERAL_UTILS_H

# define INT_MAX 2147483647

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

size_t	ft_strlen(const char *str);
void	display_error(char *error_msg, int error_id, int arg_index);

#endif
