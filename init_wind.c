/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 05:52:25 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/29 08:00:41 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

#include <fcntl.h>

void init_char(char c, t_tab *ceil, char attr[10][8])
{ int k;
  k = -1;
  while (++k < 10)
  { ft_strcpy(ceil->attr[k], attr[k]); }
  ceil->c = c; }

static void the_char(int i, int j, char c, t_tab *matrix)
{ static char attr[10][8] = {"\033[0m", "", "", "", "", "", "", "", "", ""};
  init_char(c, &(matrix[i]), attr);
  init_char(c, &(matrix[j]), attr); }

static void put_slide(t_term *coucou)
{ int i;
  i = -1;
  while (++i < SLID[2])
  { CPY(MATR[SLID[1]][WIND[4] + SLID[0] + i].attr[2], "\033[47m"); }}

static void put_cursor(t_term *coucou)
{ int coord[2];
  int i;
  get_coords(coord, CURS, coucou);
  CPY(MAPP[coord[1]][coord[0]]->attr[1], "\033[4m");
  MATR[MCOR[1]][MCOR[0] - 1].c = '{';
  CPY(MATR[MCOR[1]][MCOR[0] - 1].attr[3], "\033[46m");
  CPY(MATR[MCOR[1]][MCOR[0] - 1].attr[2], "\033[31m");
  MATR[MCOR[1]][MCOR[0] + coucou->size_max].c = '}';
  CPY(MATR[MCOR[1]][MCOR[0] + coucou->size_max].attr[3], "\033[46m");
  CPY(MATR[MCOR[1]][MCOR[0] + coucou->size_max].attr[2], "\033[31m");
  i = 0;
  while (MATR[MCOR[1]][MCOR[0] + i].c != '}')
  { CPY(MATR[MCOR[1]][MCOR[0] + i].attr[1], "\033[4m");
    i += 1; }}

static void put_finder(t_term *coucou)
{ int i;
  i = 0;
  while (FIND[i])
  { CPY(MATR[WIND[1]][WIND[4] + WIND[2] - 10 + i].attr[1], "\033[36m");
    MATR[WIND[1]][WIND[4] + WIND[2] - 10 + i].c = FIND[i];
    i += 1; }
  if (FINE >= 0)
  { CPY(MATR[WIND[1]][WIND[4] + WIND[2] - 10 + FINE].attr[3], "\033[46m"); }}

static void put_files(t_term *coucou)
{ int p;
  int q;
  int m;
  go_to(0, WIND[1]);
  p = 0;
  while (MAPP[p])
  { q = 0;
    while (MAPP[p][q])
    { m = 0;
      while (MAPO->name[m])
      { init_char(MAPO->name[m], &(MATR[MAPQ[1]][MAPQ[0] + m]), MAPO->attr);
        m += 1; }
      while (m < coucou->size_max)
      { init_char(' ', &(MATR[MAPQ[1]][MAPQ[0] + m]), MAPO->attr);
        m += 1; }
      q += 1; }
    p += 1; }}

void init_wind(t_term *coucou)
{ int i;
  int j;
  wind_clear(coucou);
  i = WIND[1] - 1;
  j = WIND[4];
  if ((WIND[2] < 25 && WIND[2] < SMAX + 3) || (WIND[3] < 15 && TMP > WIND[3] - 6))
  { wind_line("Fenster zu klein.", i, &j, MATR);
    return ; }
  put_files(coucou);
  put_cursor(coucou);
  wind_line("+---,---,", i, &j, MATR);
  while (j < (WIND[2] / 2) - 1 + WIND[4])
  { MATR[i][j++].c = '-'; }
  wind_line((WIND[2] + WIND[0]) % 2 == 0 ? ",," : ",,,", i, &j, MATR);
  while (j < WIND[2] + WIND[4] - 1)
  { MATR[i][j].c = '-';
    MATR[i + 1][j].c = ' ';
    MATR[i + 2][j++].c = ' '; }
  MATR[i][j].c = '+';
  j = WIND[4];
  wind_line("| X | O |", ++i, &j, MATR);
  MATR[i][WIND[2] + WIND[4] - 1].c = '|';
  j = WIND[4];
  wind_line("|---'---'", ++i, &j, MATR);
  MATR[i][WIND[2] + WIND[4] - 1].c = '|';
  j = WIND[2] + WIND[4] - 1;
  while (i < WIND[1] + WIND[3] - 4)
  { the_char(WIND[4], j, '|', MATR[++i]); }
  MATR[WIND[1] + (WIND[3] / 2) - 2][WIND[4]].c = '[';
  MATR[WIND[1] + (WIND[3] / 2) - 2][j].c = ']';
  the_char(WIND[4], j, '|', MATR[i]);
  j = WIND[4] + 1;
  while (j < WIND[2] + WIND[4] - 1)
  { MATR[i][j++].c = '_'; }
  while (j < WIND[2] + WIND[4] - 1)
  put_slide(coucou);
  put_finder(coucou);
  the_char(WIND[4], j, '|', MATR[++i]);
  the_char(WIND[4], j, '+', MATR[++i]);
  j = WIND[4] + 1;
  while (j < (WIND[2] / 2) - 1 + WIND[4])
  { MATR[i][j++].c = '-'; }
  wind_line((WIND[2] + WIND[0]) % 2 == 0 ? "''" : "'''", i, &j, MATR);
  while (j < WIND[2] + WIND[4] - 1)
  { MATR[i][j++].c = '-'; }}
