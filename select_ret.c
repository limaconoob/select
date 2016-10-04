/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_ret.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 07:28:12 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/28 05:21:45 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

void select_ret(t_term *coucou, int flag)
{ int coord[2];
  int i;
  if (flag == 0) //space
  { get_coords(coord, CURS, coucou); }
  else if (flag == 1) //MONO CLICK
  { get_coords(coord, MOUS, coucou);
    if (coord[1] == NCOL - 1)
    { i = 0;
      while (MAPP[NCOL - 1][i])
      { i += 1; }
      if (coord[0] >= i)
      { return ; }}}
  if (*coord == -1 || coord[0] < 0 || coord[1] < 0)
  { return ; }
  else if (flag == 1)
  { if (WIND[4] <= MAPP[coord[1]][coord[0]]->coord[0])
    { CURS[0] = MAPP[coord[1]][coord[0]]->coord[0] - WIND[4]; }
    else
    { WIND[4] = MAPP[coord[1]][coord[0]]->coord[0] - 2;
      CURS[0] = MAPP[coord[1]][coord[0]]->coord[0] - WIND[4]; }
    CURS[1] = MAPP[coord[1]][coord[0]]->coord[1] + 1; }
  if ((flag == 0 || flag == 1) && coucou->mapper[coord[1]] && coucou->mapper[coord[1]][coord[0]])
  { fleche_du_bas(coucou, coord);
    if (!*(MAPP[coord[1]][coord[0]]->attr[2]))
    { CPY(MAPP[coord[1]][coord[0]]->attr[2], "\033[31m");
      CPY(MAPP[coord[1]][coord[0]]->attr[3], "\033[47m");
      coucou->tab_tri[coucou->mapper[coord[1]][coord[0]]->index] = coucou->mapper[coord[1]][coord[0]]->name; }
    else
    { BZE(MAPP[coord[1]][coord[0]]->attr[2], 8);
      BZE(MAPP[coord[1]][coord[0]]->attr[3], 8);
      coucou->tab_tri[MAPP[coord[1]][coord[0]]->index] = NULL; }}}
