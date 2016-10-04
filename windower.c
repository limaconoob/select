/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windower.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 02:30:54 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/28 07:10:31 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

void windower(t_term *coucou)
{ int x;
  int y;
  int k;
  y = 0;
  if (MATR[WIND[1] - 1][WIND[4]].c == 'F')
  { while (MATR[WIND[1] - 1][WIND[4] + y].c != '.')
    { ft_putchar_fd(MATR[WIND[1] - 1][WIND[4] + y].c, 2);
      y += 1; }
    return ; }
  while (y < WIND[3])
  { go_to(WIND[0], y + WIND[1] - 1);
    x = WIND[4];
    while (x < WIND[2] + WIND[4])
    { k = -1;
      while (++k < 10)
      { ft_putstr_fd(MATR[y + WIND[1] - 1][x].attr[k], 2); }
      ft_putchar_fd(MATR[y + WIND[1] - 1][x].c, 2);
      x += 1; }
    y += 1; }}
