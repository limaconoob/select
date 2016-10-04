/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windower.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 02:30:54 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/20 06:38:50 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

void windower(int *wind, t_tab **matrix)
{ int x;
  int y;
  int k;
  y = 0;
  while (y < wind[3])
  { go_to(wind[0], y + wind[1] - 1);
    x = wind[4];
    while (x < wind[2] + wind[4])
    { k = -1;
      while (++k < 10)
      { ft_putstr_fd(matrix[y + wind[1] - 1][x].attr[k], 2); }
      ft_putchar_fd(matrix[y + wind[1] - 1][x].c, 2);
      x += 1; }
    y += 1; }}
