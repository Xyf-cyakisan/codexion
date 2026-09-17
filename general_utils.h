/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:45:27 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/17 17:27:13 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_UTILS_H
# define GENERAL_UTILS_H

# define INT_MAX 2147483647
# define ERR_NB_ARGS "Not the correct amount of arguments (needs 8)"
# define ERR_EMPTY_STR "Empty string encountered"
# define ERR_POS_INTS "First eight arguments must be positive integers"
# define ERR_SCHEDULER "Scheduler must be 'fifo' or 'edf'"
# define ERR_BIGGER_INT_MAX "No number should be bigger than the INT_MAX"
# define ERR_NB_CODERS "Number of coders must be greater than 0"
# define ERR_TIME_BURNOUT "Time to burnout must be greater than 0"
# define ERR_REQUIRED_COMP "Number of compiles required must be greater than 0"
# define ERR_BUR_S "Time to burnout needs to be greater than the operating time"
# define TRUE 1
# define FALSE -1

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef int	t_bool;

size_t	ft_strlen(const char *str);
void	display_error(char *error_msg, int error_id, int arg_index);

#endif
