/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:44:53 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/15 16:56:26 by cyakisan         ###   ########.fr       */
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
	exit(error_id);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		display_error("NULL string encountered", 2, 0);
	while (str[i] != '\0')
		++i;
	return (i);
}
