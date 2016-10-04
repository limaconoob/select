/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idle.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 22:14:28 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/28 05:25:36 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"
#include <stdlib.h>

int idle(char *buf, t_term *coucou)
{ int coord[2];
  get_coords(coord, CURS, coucou);
  BZE(MAPP[coord[1]][coord[0]]->attr[1], 8);
  if (*buf == ESC)
  { if (mouse(buf, coucou))
    { return (4); }
    else if (!fleche(buf, coucou))
    { return (5); }
    else if (buf[3] == SUPPR) //delete
    { return (3); }}
  else if (*buf == DEL) //delete
  { return (3); }
  return (0); }
