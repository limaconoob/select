/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fleche_de_droite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:02:01 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/28 07:36:17 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

void fleche_de_droite(t_term *coucou, int *coord)
{ if (CURS[0] + (2 * SMAX) + 3 < WIND[0] + WIND[2] && coord[1] != NCOL - 2)
  { CURS[0] += SMAX + 3; }
  else if (CURS[0] + (2 * SMAX) + 3 >= WIND[0] + WIND[2] && coord[1] < NCOL - 2)
  { WIND[4] += SMAX + 3; }
  else if (CURS[0] + WIND[4] + (2 * SMAX) + 5 < SIZE)
  { WIND[4] += SMAX + 3; }
  else if (coord[1] == NCOL - 2 && MAPP[coord[1] + 1][coord[0]])
  { CURS[0] = WIND[0] + WIND[2] - SMAX - 2;
    WIND[4] = SIZE - WIND[2]; }
  else if (coord[1] == NCOL - 2)
  { int i = 0;
    while (MAPP[NCOL - 1][i])
    { i += 1; }
    CURS[1] = i + WIND[1] + 2;
    CURS[0] = WIND[0] + WIND[2] - (SMAX + 2);
    WIND[4] = SIZE - WIND[2]; }
  else
  { WIND[4] = 0;
    CURS[0] = WIND[0] + 2; }}
