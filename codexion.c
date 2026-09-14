/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:33:55 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/14 14:46:45 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;

	if (ac == 9)
	{
		i = -1;
		while (av[++i])
			printf("%s\n", av[i]);
	}
	else
	{
		printf("flop\n");
		return (1);
	}
	return (0);
}
