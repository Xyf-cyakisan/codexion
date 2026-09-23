/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 11:44:53 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/23 16:45:21 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general_utils.h"

void	display_error(char *error_msg, int error_id, int arg_index)
{
	if (arg_index == 0)
		fprintf(stderr, "ERROR (%d): %s\n", error_id, error_msg);
	else
		fprintf(stderr, "ERROR (%d): %s (argument %d)\n", error_id, error_msg,
			arg_index);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (display_error(ERR_EMPTY_STR, 2, 0), FALSE);
	while (str[i] != '\0')
		++i;
	return (i);
}
