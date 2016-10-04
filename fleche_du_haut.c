/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fleche_du_haut.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 08:42:08 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/20 08:45:49 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

void fleche_du_haut(t_term *coucou, int *coord)
{ int i;
  BZE(MAPP[coord[1]][coord[0]]->attr[1], 8);
  if (CURS[1] > WIND[1] + 3 && CURS[0] - ((coucou->size_max + 3) > WIND[0] || CURS[0] < (coucou->size_max + 3)) && (CURS[0] > WIND[0] + 2 || CURS[1] > WIND[1] + 3))
  { CURS[1] -= 1; }
  else if (CURS[1] == WIND[1] + 3)
  { CURS[1] = WIND[1] + WIND[3] - 4;
    if (CURS[0] - (coucou->size_max + 3) > WIND[0])
    { CURS[0] -= coucou->size_max + 3; }
    else if (WIND[4] - (coucou->size_max + 3) > 0)
    { WIND[4] -= coucou->size_max + 3; }
    else if (WIND[4] > 0)
    { WIND[4] = 0;
      CURS[0] = 2; }
    else
    { i = 0;
      CURS[0] = WIND[0] + WIND[2] - (coucou->size_max + 2);
      WIND[4] = SIZE - WIND[2];
      while (MAPP[coucou->nb_col - 1][i])
      { i += 1; }
      CURS[1] = i + WIND[1] + 2; }}}
