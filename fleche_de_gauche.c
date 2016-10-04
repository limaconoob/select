/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fleche_de_gauche.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:10:24 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/28 04:40:42 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

void fleche_de_gauche(t_term *coucou, int *coord)
{ int i;
  if (CURS[0] - (SMAX + 3) > WIND[0])
  { CURS[0] -= SMAX + 3; }
  else if (WIND[4] - (SMAX + 3) > 0)
  { WIND[4] -= SMAX + 3; }
  else if (WIND[4] > 0)
  { WIND[4] = 0;
    CURS[0] = 2 + WIND[0]; }
  else
  { CURS[0] = WIND[0] + WIND[2] - (SMAX + 2);
    WIND[4] = SIZE - WIND[2];
    if (!MAPP[NCOL - 1][coord[0]])
    { i = 0;
      while (MAPP[NCOL - 1][i])
      { i += 1; }
      CURS[1] = i + WIND[1] + 2; }}}
