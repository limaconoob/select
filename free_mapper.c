/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mapper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 09:22:01 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/29 05:11:15 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"
#include <stdlib.h>

void free_mapper(t_term *coucou)
{ int i;
  int j;
  i = 0;
  while (i < coucou->nb_col)
  { j = 0;
    while (MAPP[i][j])
    { free(MAPP[i][j]);
      j += 1; }
    free(MAPP[i][j]);
    free(MAPP[i]);
    i += 1; }
  free(MAPP[i]);
  free(MAPP); }
