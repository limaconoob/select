/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 02:34:24 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/20 06:36:18 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"
#include <stdlib.h>

void get_names(char **argv, t_term *coucou)
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
    coucou->tab_tri[i - 1] = argv[i];
    len = ft_strlen(argv[i]);
    if (coucou->size_max < len)
    { coucou->size_max = len; }}
  coucou->tab_tri[i - 1] = NULL;
  ft_tri(coucou->tab_tri);

  term_coord(WIND);
  WIND[0] -= 1;
  CURS[1] = WIND[1] + 3;
  WIND[3] = TERM[1] - WIND[1] + 1;
  //printf("term::%d, wind1::%d, wind3::%d\n", TERM[1], WIND[1], WIND[3]);
  //exit(1);

  coucou->nb_col = coucou->nb_files / (WIND[3] - 6);

  if (coucou->nb_files % (WIND[3] - 6) != coucou->nb_files && coucou->nb_files % (WIND[3] - 6))
  { coucou->nb_col += 1; }
  if (!((MAPP = (t_map***)malloc(sizeof(t_map**) * (coucou->nb_col + 1)))))
  { select_error(Malloc, "mapper in get_names"); }
  int q = WIND[3] - 6;
  int p = -1;
  int k;
  i = 0;
  while (coucou->tab_tri[i])
  { if (q < WIND[3] - 6)
    { if (!((MAPP[p][q] = (t_map*)malloc((sizeof(t_map))))))
      { select_error(Malloc, "mapper[p][q] in get_names"); }
      MAPP[p][q]->name = coucou->tab_tri[i];
      MAPP[p][q]->index = i;
      coucou->tab_tri[i++] = NULL;
      MAPP[p][q]->coord[0] = (p * (coucou->size_max + 3)) + 2;
      MAPP[p][q]->coord[1] = q + 2 + WIND[1];
      /*      ft_putchar('(');
            ft_putnbr(MAPP[p][q]->coord[0]);
            ft_putchar(',');
            ft_putnbr(MAPP[p][q]->coord[1]);
            ft_putchar(')');
            ft_putchar('\n'); */
      k = 0;
      while (++k < 10)
      { ft_bzero(MAPP[p][q]->attr[k], 8); }
      ft_strcpy(*(MAPP[p][q]->attr), "\033[0m");
      q++; }
    else
    { if (p >= 0)
      { MAPP[p][q] = NULL; }
      p++;
      if (!((MAPP[p] = (t_map**)malloc(sizeof(t_map*) * (WIND[3] - 5)))))
      { select_error(Malloc, "mapper[p] in get_names"); }
      q = 0; }}
  MAPP[p][q] = NULL;
  MAPP[++p] = NULL;
  coucou->mat_size = (p * (coucou->size_max + 3)) + 1;
  WIND[2] = coucou->mat_size > TERM[0] ? TERM[0] : coucou->mat_size; }
