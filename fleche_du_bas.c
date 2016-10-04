/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fleche_du_bas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 07:56:23 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/28 07:25:33 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

void fleche_du_bas(t_term *coucou, int *coord)
{ if (CURS[1] < WIND[1] + WIND[3] - 4 && CURS[0] + coucou->size_max < WIND[0] + WIND[2] && MAPP[coord[1]][coord[0] + 1])
  { CURS[1] += 1; }
  else if (CURS[1] == WIND[1] + WIND[3] - 4 || !MAPP[coord[1]][coord[0] + 1])
  { CURS[1] = WIND[1] + 3;
    if (CURS[0] + (2 * coucou->size_max) + 3 < WIND[0] + WIND[2] && coord[1] != coucou->nb_col - 2)
    { CURS[0] += coucou->size_max + 3; }
    else if (CURS[0] + WIND[4] + (2 * coucou->size_max) + 5 < SIZE)
    { WIND[4] += coucou->size_max + 3; }
    else if (coord[1] == coucou->nb_col - 2 || MAPP[coord[1]][coord[0] + 1])
    { CURS[0] = WIND[0] + WIND[2] - coucou->size_max - 2;
      WIND[4] = SIZE - WIND[2]; }
    else
    { WIND[4] = 0;
      CURS[0] = WIND[0] + 2; }}}
