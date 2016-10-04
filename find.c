/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:53:23 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/23 03:49:40 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

static void find_apply(t_term *coucou)
{ int coord[2];
  int cpy[2];
  int len;
  len = LEN(FIND);
  get_coords(coord, CURS, coucou);
  MCPY(cpy, coord, 2 * INT);
  coord[0] += 1;
  while (MAPP[coord[1]])
  { while (MAPP[coord[1]][coord[0]])
    { if (!NCMP(MAPP[coord[1]][coord[0]]->name, FIND, len))
      { if (coord[0] != cpy[0] && coord[1] != cpy[1])
        { if (MCOR[0] > WIND[4] && MCOR[0] < WIND[4] + WIND[2])
          { CURS[0] = MCOR[0] - WIND[4];
            CURS[1] = MCOR[1]; }}
        break ; }
      coord[0] += 1; }
    coord[0] = 0;
    coord[1] += 1; }}

int find(t_term *coucou, char *buf)
{ if (ft_isprint(*buf) && !buf[1] && FINE < 8)
  { FIND[FINE] = *buf;
    FINE += 1; }
  else if (*buf == DEL && FINE > 0)
  { CPY(&FIND[FINE - 1], &FIND[FINE]);
    FINE -= 1; }
  else if (*buf == ESC && !buf[2])
  { BZE(FIND, SMAX);
    FINE = -1;
    return (0); }
  else if (*buf == '\n' || *buf == TAB)
  { find_apply(coucou);
    FINE = -1;
    return (0); }
  else if (*buf == ESC && buf[2] == LIN)
  { if (FINE > 0)
    { FINE -= 1; }}
  else if (*buf == ESC && buf[2] == REC)
  { if (FINE < (int)LEN(FIND) && FINE < 8)
    { FINE += 1; }}
  return (1); }
