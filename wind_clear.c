/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wind_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 01:38:39 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/27 07:47:54 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

void wind_clear(t_term *coucou)
{ static char attr[10][8] = {"\033[0m", "", "", "", "", "", "", "", "", ""};
  int i;
  int j;
  i = 0;
  while (i < WIND[3])
  { j = WIND[4] - 1;
    while (++j < WIND[2] + WIND[4])
    { init_char(' ', &MATR[i + WIND[1] - 1][j], attr); }
    i += 1; }}
