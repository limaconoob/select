/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 02:27:25 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/27 07:51:24 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

void put_window(t_term *coucou, char (*buf)[12])
{ init_wind(coucou);
  term_init(0, coucou);
  go_to(WIND[0], WIND[1] - 1);
  windower(coucou);
  if (buf)
  { BZE(*buf, 12); }}
