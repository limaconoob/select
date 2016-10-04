/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 04:01:11 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/29 04:28:32 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void deplacement(t_term *coucou, char buf[12])
{ int p;
  int q;
  windower(coucou);
  if (*buf == 'q' && WIND[0] + WIND[2] < TERM[0])
  { WIND[0] += 1;
    CURS[0] += 1; }
  else if (*buf == 's' && WIND[1] + WIND[3] <= TERM[1])
  { WIND[1] += 1;
    CURS[1] += 1;
    p = 0;
    while (MAPP[p])
    { q = 0;
      while (MAPO)
      { MAPQ[1] += 1;
        q += 1; }
      p += 1; }}
  else if (*buf == 'd' && WIND[0])
  { WIND[0] -= 1;
    CURS[0] -= 1; }
  else if (*buf == 'f' && WIND[1] - 1)
  { WIND[1] -= 1;
    CURS[1] -= 1;
    p = 0;
    while (MAPP[p])
    { q = 0;
      while (MAPO)
      { MAPQ[1] -= 1;
        q += 1; }
      p += 1; }}}
