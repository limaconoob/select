/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redimension.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 07:59:20 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/29 09:00:06 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

void redimension(t_term *coucou, char buf[12])
{ int p;
  int q;
  t_map *tmp;
  t_map *tmp2;
  t_map ***new_map;

  p = 0;
  q = 0;
  windower(coucou);

  if (*buf == 'a' && WIND[2] > SMAX + 4)
  { SLID[0] += 1;
    CURS[0] += 1;
    WIND[0] += 1;
    WIND[2] -= 1;
    if (CURS[0] + SMAX + 2 > WIND[0] + WIND[2])
    { WIND[4] += 1; }}
  else if (*buf == 'e' && WIND[2] > SMAX + 4)
  { WIND[2] -= 1;
    if (CURS[0] + SMAX + 2 > WIND[0] + WIND[2])
    { WIND[4] += 1; 
      CURS[0] -= 1; }}

  else if (*buf == 'z' /*&& TMP > WIND[3] - 6*/)
  { CURS[1] += 1;
    WIND[1] += 1;
    p = 0;
 //   go_to(0, WIND[1]);
    q = 0;
    while (q < WIND[3] - 7)
    { MAPQ[1] += 1;
      q += 1; }
    while (p + 2 < NCOL)
    { tmp = MAPP[p + 1][0];
      tmp2 = MAPP[p + 1][1];
//      printf("1(%d, %d)pq\n", p, q);
      MCPY(MAPQ, tmp->coord, 2 * INT);
      tmp->coord[1] += 1;
      *(MAPP[p + 1]) = MAPO;
      MAPO = NULL;
      q = 1;
      p += 1;
      while (q < WIND[3] - 7)
      { MAPO = tmp;
        tmp = tmp2;
//      printf("2(%d, %d)pq\n", p, q);
        tmp->coord[1] += 1;
        if (q < WIND[3] - 6)
        { tmp2 = MAPP[p][q + 1]; }
        q += 1; }}
    tmp = MAPP[p + 1][0];
    tmp->coord[1] += 1;
    tmp2 = MAPP[p + 1][1];
    tmp2->coord[1] += 1;
    MCPY(MAPQ, tmp->coord, 2 * INT);
    MAPP[p + 1][0] = MAPO;
   /* go_to(0, WIND[1]);
      printf("3(%d, %d)pq;\n", p, q);
     printf("tmp::%s:(%d, %d), tmp2::%s:(%d, %d), MAPO::%s:(%d, %d)\n", tmp->name, tmp->coord[0], tmp->coord[1], tmp2->name, tmp2->coord[0], tmp2->coord[1], MAPO->name, MAPQ[0], MAPQ[1]);
*/    MAPO = NULL;
    q = 1;
    p += 1;
//    printf("WIND! 1::%d, 3::%d\n", WIND[1], WIND[3]);
    while (tmp2)
    { tmp->coord[1] += 1;
      MAPO = tmp;
      tmp = tmp2;
      tmp2 = MAPP[p][q + 1];
      if (tmp2)
      tmp2->coord[1] += 1;

  //    printf("3(%d, %d)pq;\n", p, q);
//      if (tmp2)
//     printf("tmp::%s:(%d, %d), tmp2::%s:(%d, %d), MAPO::%s:(%d, %d)\n", tmp->name, tmp->coord[0], tmp->coord[1], tmp2->name, tmp2->coord[0], tmp2->coord[1], MAPO->name, MAPQ[0], MAPQ[1]);

  //    printf("3(%d, %d)pq; (%d, %d)\n", p, q, MAPO->coord[0], MAPO->coord[1]);
  //    printf("4(%d, %d)pq\n", p, q);
      q += 1; }
    if (q != WIND[3] - 7)
    { tmp->coord[1] += 1;
      MAPO = tmp;
  //    printf("5(%d, %d)pq\n", p, q);
      q += 1;
      MAPO = NULL; }
    else
    { NCOL += 1;
      tmp->coord[0] = MAPQ[0] + SMAX + 3;
      tmp->coord[1] = WIND[1] + 2;
      if (!((new_map = (t_map***)malloc(sizeof(t_map**) * (NCOL + 1)))))
      { select_error(Malloc, "mapper in get_names"); }
      p = 0;
      while (MAPP[p])
      { new_map[p] = MAPP[p];
        p += 1; }
      if (!((new_map[p] = (t_map**)malloc(sizeof(t_map*) * TERM[1]))))
      { select_error(Malloc, "mapper[p] in get_names"); }
      *(new_map[p]) = tmp;
      new_map[p][1] = NULL;
      new_map[p + 1] = NULL;
      free(MAPP);
      MAPP = new_map; }
  //    exit(1);
    WIND[3] -= 1; }
  else if (*buf == 'r')
  { if (WIND[3] > 7)
    { SLID[1] -= 1;
      WIND[3] -= 1; }}}
