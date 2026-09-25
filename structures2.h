/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyakisan <cyakisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 21:41:49 by cyakisan          #+#    #+#             */
/*   Updated: 2026/09/25 21:44:51 by cyakisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES2_H
# define STRUCTURES2_H

# include <stddef.h>
# include <stdint.h>

typedef struct s_coder	t_coder;

typedef struct s_request
{
	t_coder			*coder;
	uint64_t		last_compile;
}	t_request;

typedef struct s_heap
{
	t_request		requests[2];
	size_t			size;
}	t_heap;

#endif