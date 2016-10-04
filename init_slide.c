/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_slide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 02:24:58 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/20 02:26:23 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void init_slide(t_term *coucou)
{ SLID[0] = WIND[4] + 1;
  SLID[1] = WIND[1] + WIND[3] - 3;
  if (WIND[2] < coucou->mat_size)
  { SLID[2] = WIND[2] - (coucou->mat_size / WIND[2]) - 2;
    if (coucou->mat_size % WIND[2])
    { SLID[2] -= 1; }}
  else
  { SLID[2] = WIND[2] - 2; }}
