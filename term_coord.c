/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:44:30 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/20 04:20:34 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/uio.h>
#include <sys/types.h>
#include <unistd.h>

void term_coord(int *coord)
{ char buf[9];
	int i;
	ft_bzero(buf, 9);
  ft_bzero(coord, 2 * sizeof(int));
	i = 2;
	write(2, "\e[6n", 5);
	read(2, buf, 9);
	while (ft_isdigit(buf[i]))
	{ coord[1] = (coord[1] * 10) + buf[i++] - '0'; }
  i++;
	while (ft_isdigit(buf[i]))
	{ coord[0] = (coord[0] * 10) + buf[i++] - '0'; }}
