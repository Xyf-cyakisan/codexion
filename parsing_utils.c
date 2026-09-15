/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:26:54 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/15 16:58:11 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general_utils.h"

void	ft_check_number_validity(char *str, int arg_index)
{
	size_t	i;

	i = 0;
	if (!str)
		display_error("NULL string encountered", 2, 0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			display_error("Every argument must be a positive integer",
				3, arg_index);
		++i;
	}
}

void	ft_check_scheduler(char *str)
{
	if (strcmp(str, "fifo") && strcmp(str, "edf"))
		display_error("Scheduler must be 'fifo' or 'edf'", 4, 9);
}

int	ft_atoi(const char *nptr, int arg_index)
{
	unsigned int	i;
	long int		result;

	i = 0;
	result = 0;
	if (ft_strlen(nptr) >= 11)
		display_error("No number should be bigger"
			" than the INT_MAX", 5, arg_index);
	while (nptr[i] != '\0')
	{
		result = result * 10 + (nptr[i] - '0');
		++i;
	}
	if (result > INT_MAX)
		display_error("No number should be bigger"
			" than the INT_MAX", 5, arg_index);
	return ((int)result);
}
