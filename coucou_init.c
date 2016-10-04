/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coucou_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 09:26:06 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/15 08:37:10 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/ioctl.h>

static void coucou_clear(t_term *coucou)
{ coucou->nb_files = 0;
  coucou->size_max = 0;
  coucou->curs[0] = 2;
  coucou->curs[1] = 0;
  coucou->curs[2] = 0;
  coucou->mous[0] = 2;
  coucou->mous[1] = 0;
  coucou->mous[2] = 0;
  coucou->wind[0] = 0;
  coucou->wind[1] = 0;
  coucou->wind[2] = 0;
  coucou->wind[3] = 0;
  coucou->wind[4] = 0; }

t_term *coucou_init(void)
{ static t_term coucou[1];
  struct winsize w;
  coucou_clear(coucou);
  if (ioctl(0, TIOCGWINSZ, &w) == -1)
  { select_error(TermInit, "TermKappa"); }
  get_size(w.ws_col, w.ws_row, NULL);
  get_size(-1, 0, coucou);
  return (coucou); }
