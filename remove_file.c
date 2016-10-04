/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 08:53:16 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/28 06:09:56 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

void remove_file(t_term *coucou, int *coord)
{ int tmp[2];
  tmp[0] = coord[0];
  tmp[1] = coord[1];
  TTRI[MAPP[coord[1]][coord[0]]->index] = NULL;
  TMP -= 1;
  if (!(MAPP[coord[1]][coord[0] + 1]))
  { MCOR[1] -= 1; }
  while (MAPP[coord[1]])
  { while (MAPP[coord[1]][coord[0] + 1])
    { MAPP[coord[1]][coord[0]] = MAPP[coord[1]][coord[0] + 1];
      MCOR[1] -= 1;
      coord[0] += 1; }
    if (MAPP[coord[1] + 1])
    { tmp[0] = MCOR[0];
      tmp[1] = MCOR[1] + 1;
      MAPP[coord[1]][coord[0]] = MAPP[coord[1] + 1][0];
      MCOR[0] = tmp[0];
      MCOR[1] = tmp[1]; }
    else if (coord[0] && coord[1] == NCOL - 1)
    { if (tmp[0] == coord[0] && tmp[1] == coord[1])
      { CURS[1] -= 1; }
      if (NCOL == 1)
      { windower(coucou);
        WIND[3] -= 1; }
      MAPP[coord[1]][coord[0]] = NULL; }
    else if (!coord[0] && coord[1])
    { if (tmp[0] == coord[0] && tmp[1] == coord[1])
      { CURS[1] = WIND[1] + WIND[3] - 4;
        CURS[0] -= SMAX + 3; }
      MAPP[coord[1]] = NULL;
      NCOL -= 1; }
    else
    { NCOL -= 1;
      do_exit(coucou); }
    coord[1] += 1;
    coord[0] = 0; }}
