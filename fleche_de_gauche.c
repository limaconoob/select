/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fleche_de_gauche.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:10:24 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/20 09:12:13 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

void fleche_de_gauche(t_term *coucou, int *coord)
{ int i;
  BZE(MAPP[coord[1]][coord[0]]->attr[1], 8);
  if (CURS[0] - (coucou->size_max + 3) > WIND[0])
  { CURS[0] -= coucou->size_max + 3; }
  else if (WIND[4] - (coucou->size_max + 3) > 0)
  { WIND[4] -= coucou->size_max + 3; }
  else if (WIND[4] > 0)
  { WIND[4] = 0;
    CURS[0] = 2; }
  else
  { CURS[0] = WIND[0] + WIND[2] - (coucou->size_max + 2);
    WIND[4] = SIZE - WIND[2];
    if (!MAPP[coucou->nb_col - 1][coord[0]])
    { i = 0;
      while (MAPP[coucou->nb_col - 1][i])
      { i += 1; }
      CURS[1] = i + WIND[1] + 2; }}}
