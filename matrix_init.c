/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 06:07:48 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/22 21:48:59 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"
#include <stdlib.h>

void matrix_init(t_term *coucou)
{ int i;
  int j;
  int k;
  if (!((MATR = (t_tab**)malloc(sizeof(t_tab*) * TERM[1]))))
  { select_error(Malloc, "matrix in matrix init"); }
  i = -1;
  while (++i < TERM[1])
  { if (!((MATR[i] = (t_tab*)malloc(sizeof(t_tab) * coucou->mat_size))))
    { select_error(Malloc, "matrix in matrix init"); }
    j = -1;
    while (++j < coucou->mat_size)
    { k = 0;
      while (++k < 10)
      { ft_bzero(MATR[i][j].attr[k], 8); }
      ft_strcpy(*(MATR[i][j].attr), "\033[0m");
      MATR[i][j].c = ' '; }}}
