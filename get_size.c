/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 05:32:17 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/26 01:05:45 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <stdlib.h>

void get_size(int *size, t_term *coucou)
{ static int sx;
  static int sy;
  static t_term *stock = NULL;
  if (!size)
  { TERM[0] = sx;
    TERM[1] = sy;
    stock = coucou; }
  else
  { sx = size[0];
    sy = size[1]; }}
