/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 09:12:39 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/28 06:11:11 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"
#include <fcntl.h>

void put_result(t_term *coucou)
{ int i;
  int flag;
  i = 0;
  flag = 1;
  go_to(0, WIND[1] - 1);
  while (i < NFIL)
  { if (TTRI[i])
    { ft_putstr(TTRI[i]);
      ft_putchar(' ');
      flag = 0; }
    i += 1; }
  if (flag)
  { ft_putchar('\n'); }}
