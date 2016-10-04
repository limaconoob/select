/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coucou_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 09:26:06 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/28 07:26:01 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/ioctl.h>

static void coucou_clear(t_term *coucou)
{ NFIL = 0;
  SMAX = 0;
  FINE = -1;
  FIND = NULL;
  CURS[0] = 2;
  BZE(&CURS[1], 2 * INT);
  MOUS[0] = 2;
  BZE(&MOUS[1], 2 * INT);
  BZE(WIND, 5 * INT); }

t_term *coucou_init(void)
{ static t_term coucou[1];
  coucou_clear(coucou);
  get_size(term_size(), NULL);
  get_size(NULL, coucou);
  return (coucou); }
