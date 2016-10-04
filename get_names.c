/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 02:34:24 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/29 05:14:26 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"
#include <stdlib.h>

void get_names(char **argv, t_term *coucou)
{ int i;

  ttri_init(coucou, argv);
  term_coord(WIND);
  TMP = NFIL;
  WIND[0] -= 1;
  CURS[1] = WIND[1] + 3;
  WIND[3] = TERM[1] - WIND[1] + 1;

  NCOL = NFIL / (WIND[3] - 6);

  if (NFIL % (WIND[3] - 6) != NFIL && NFIL % (WIND[3] - 6))
  { NCOL += 1; }
  else if (NFIL % (WIND[3] - 6) == NFIL)
  { WIND[3] = NFIL + 6;
    NCOL = 1; }
  if (!((MAPP = (t_map***)malloc(sizeof(t_map**) * (NCOL + 1)))))
  { select_error(Malloc, "mapper in get_names"); }
  int q = WIND[3] - 6;
  int p = -1;
  int k;
  i = 0;
  while (TTRI[i])
  { if (q < WIND[3] - 6)
    { if (!((MAPP[p][q] = (t_map*)malloc((sizeof(t_map))))))
      { select_error(Malloc, "mapper[p][q] in get_names"); }
      MAPP[p][q]->name = TTRI[i];
      MAPP[p][q]->index = i;
      TTRI[i++] = NULL;
      MAPP[p][q]->coord[0] = (p * (SMAX + 3)) + 2;
      MAPP[p][q]->coord[1] = q + 2 + WIND[1];
      k = 0;
      while (++k < 10)
      { BZE(MAPP[p][q]->attr[k], 8); }
      CPY(*(MAPP[p][q]->attr), "\033[0m");
      q++; }
    else
    { if (p >= 0)
      { MAPP[p][q] = NULL; }
      p++;
     // if (!((MAPP[p] = (t_map**)malloc(sizeof(t_map*) * (WIND[3] - 5)))))
      if (!((MAPP[p] = (t_map**)malloc(sizeof(t_map*) * TERM[1]))))
      { select_error(Malloc, "mapper[p] in get_names"); }
      q = 0; }}
  MAPP[p][q] = NULL;
  MAPP[++p] = NULL;
  MSIZ = (p * (SMAX + 3)) + 1;
  WIND[2] = MSIZ > TERM[0] ? TERM[0] : MSIZ;
  if (!((FIND = (char*)malloc(SMAX + 1))))
  { select_error(Malloc, "find in all_init"); }
  BZE(FIND, SMAX + 1); }
