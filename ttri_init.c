/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttri_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 05:09:34 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/22 21:41:06 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"
#include <stdlib.h>

void ttri_init(t_term *coucou, char **argv)
{ int i;
  int len;
  i = 0;
  while (argv[++i])
  { if (!*argv[i])
    { continue ; }
    coucou->nb_files += 1; }
  if (!((coucou->tab_tri = (char**)malloc(sizeof(char*) * (coucou->nb_files + 1)))))
  { select_error(Malloc, "tab in get_names"); }
  i = 0;
  while (argv[++i])
  { if (!*argv[i])
    { continue ; }
    TTRI[i - 1] = argv[i];
    len = LEN(argv[i]);
    if (len < 30 && SMAX < len)
    { SMAX = len; }
    else if (len >= 30)
    { SMAX = 30; }}
  TTRI[i - 1] = NULL;
  ft_tri(TTRI); }
