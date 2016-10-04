/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 23:10:06 by jpepin            #+#    #+#             */
/*   Updated: 2016/10/01 22:30:11 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

void command_line(t_term *coucou)
{ char buf[12];
  int k;
  int coord[2];
  static int tab_flag = 0;
  static int find_flag = 0;
  static int flag = 0;
  BZE(buf, 12);
  while (read(0, buf, 12))
  { wind_clear(coucou);
    k = idle(buf, coucou);
    get_coords(coord, CURS, coucou);

    if (*buf == TAB && !tab_flag && *FIND)
    { tab_flag = 1; }
    else if (*buf == TAB && tab_flag == 1 && *FIND)
    { tab_flag = 0; }
    else if (*buf == ATF && !find_flag)
    { find_flag = 1;
      FINE = 0; }
    else if (find_flag == 1)
    { find_flag = find(coucou, buf); }

    else if (buf[2] == UNT)
    { fleche_du_bas(coucou, coord); }
    else if (buf[2] == TOP)
    { fleche_du_haut(coucou, coord); }
    else if (buf[2] == REC)
    { fleche_de_droite(coucou, coord); }
    else if (buf[2] == LIN)
    { fleche_de_gauche(coucou, coord); }

    else if (*buf == SPC)
    { select_ret(coucou, 0); }
    else if (*buf == DEL || !NCMP(buf, "\033[3~", 4))
    { remove_file(coucou, coord); }

    else if (*buf == ESC && !buf[1])
    { do_exit(coucou); }

    else if (((*buf == 'a' || *buf == 'e') && WIND[2] > 15) || ((*buf == 'z' || *buf == 'r') && WIND[3] > 15))
    { redimension(coucou, buf); }
    else if (*buf == 'q' || *buf == 'd' || *buf == 's' || *buf == 'f')
    { deplacement(coucou, buf); }

/*       SCHNELL RECHT / LINKS 
    else if (buf[2] == LIN && WIND[4] - WIND[2] + 2 >= 0)
    { BZE(MAPP[coord[1]][coord[0]]->attr[1], 8);
      WIND[4] -= (WIND[2] / NCOL) * SMAX - 2; }
    else if (buf[2] == REC && WIND[4] + (2 * WIND[2]) - 2 <= SIZE)
    { BZE(MAPP[coord[1]][coord[0]]->attr[1], 8);
      WIND[4] += (WIND[2] / NCOL) * SMAX - 2; }

    else if (buf[2] == LIN)
    { BZE(MAPP[coord[1]][coord[0]]->attr[1], 8);
      WIND[4] = 0; }
    else if (buf[2] == REC)
    { BZE(MAPP[coord[1]][coord[0]]->attr[1], 8);
      WIND[4] = SIZE - WIND[2]; }
*/
  
    // SLIDE
    else if (k == 4 && ((MOUS[2] & 0x7FFF) == LCK || (MOUS[2] & 0x7FFF) == DDL) && MOUS[1] == WIND[1] + WIND[3] - 2 && MOUS[0] > SLID[0] && MOUS[0] <= SLID[0] + SLID[2])
    { ; }
//    { slide(coucou); }

    // MOUSE (select)
    else if (k == 4 && (MOUS[2] & 0x7FFF) == LCK /*|| (MOUS[2] & 0x7FFF) == DDL)*/ && !(MOUS[2] & 0x8000) && MOUS[1] > WIND[1] + 2 && MOUS[1] < WIND[1] + WIND[3] - 1)
    { select_ret(coucou, 1); }

    // MOUSE (return)
    else if (k == 4 && (MOUS[2] & 0x7FFF) == LCK && !(MOUS[2] & 0x8000) && MOUS[1] == WIND[1] + 1 && MOUS[0] > WIND[0] + 5 && MOUS[0] <= WIND[0] + 8)
    { flag ^= 0x0002; }

    // MOUSE (return)
    else if (k == 4 && (MOUS[2] & 0x7FFF) == LCK && MOUS[1] == WIND[1] + 1 && MOUS[0] > WIND[0] + 5 && MOUS[0] <= WIND[0] + 8 && (flag & 0x0002))
    { windower(coucou);
      break ; }

    // MOUSE (quit)
    else if (k == 4 && (MOUS[2] & 0x7FFF) == LCK && !(MOUS[2] & 0x8000) && MOUS[1] == WIND[1] + 1 && MOUS[0] > WIND[0] + 1 && MOUS[0] <= WIND[0] + 4)
    { flag ^= 0x0001; }

    // MOUSE (quit)
    else if (k == 4 && (MOUS[2] & 0x7FFF) == LCK && MOUS[1] == WIND[1] + 1 && MOUS[0] > WIND[0] + 1 && MOUS[0] <= WIND[0] + 4 && (flag & 0x0001))
    { do_exit(coucou); }

    // UNQUIT
    else if (k == 4 && (MOUS[2] & 0x7FFF) == LCK && (flag & 0x0001))
    { flag &= 0xFFFE; }

    // ENTER (return)
    else if (k == 8 || *buf == '\n')
    { windower(coucou);
      break ; }

    if (CURS[0] + WIND[4] < SIZE)
    { get_coords(coord, CURS, coucou);
      if (MAPP[coord[1]][coord[0]]->coord[0] < WIND[4])
      { CURS[0] += SMAX; }
      else if (MAPP[coord[1]][coord[0]]->coord[0] > WIND[4] + WIND[2])
      { CURS[0] -= SMAX; }}

    if (WIND[4] + WIND[2] > SIZE)
    { if (WIND[4] + WIND[2] > TERM[0])
      { if (CURS[0] + SMAX + 3 < WIND[2])
        { CURS[0] += SMAX + 3; }
        if (SIZE - WIND[2] >= 0)
        { WIND[4] = SIZE - WIND[2]; }
        else
        { windower(coucou);
          WIND[2] = SIZE;
          CURS[0] = WIND[0] + SIZE - (SMAX + 2);
          WIND[4] = 0; }}
      else
      { windower(coucou);
        WIND[4] = 0;
        WIND[2] = SIZE; }}

   /*     int fd = open("/dev/ttys007", O_WRONLY);
        ft_putstr_fd("WIND! 0::", fd);
        ft_putnbr_fd(WIND[0], fd);
        ft_putstr_fd(", 1::", fd);
        ft_putnbr_fd(WIND[1], fd);
        ft_putstr_fd(", 2::", fd);
        ft_putnbr_fd(WIND[2], fd);
        ft_putstr_fd(", 3::", fd);
        ft_putnbr_fd(WIND[3], fd);
        ft_putstr_fd(", 4::", fd);
        ft_putnbr_fd(WIND[4], fd);
        ft_putstr_fd(", SIZE::", fd);
        ft_putnbr_fd(SIZE, fd);
        ft_putstr_fd(", SMAX::", fd);
        ft_putnbr_fd(SMAX, fd);
        ft_putchar_fd('\n', fd);
*/
      put_window(coucou, &buf); }}

        /* -------------- DEBUG -----------------

        int fd = open("/dev/ttys007", O_WRONLY);
        ft_putstr_fd("WIND! 0::", fd);
        ft_putnbr_fd(WIND[0], fd);
        ft_putstr_fd(", 1::", fd);
        ft_putnbr_fd(WIND[1], fd);
        ft_putstr_fd(", 2::", fd);
        ft_putnbr_fd(WIND[2], fd);
        ft_putstr_fd(", 3::", fd);
        ft_putnbr_fd(WIND[3], fd);
        ft_putstr_fd(", 4::", fd);
        ft_putnbr_fd(WIND[4], fd);
        ft_putstr_fd(", SIZE::", fd);
        ft_putnbr_fd(SIZE, fd);
        ft_putstr_fd(", SMAX::", fd);
        ft_putnbr_fd(SMAX, fd);
        ft_putchar_fd('\n', fd);
        close(fd);

    if (*buf == 'y')
    { int v;
      int w;
      go_to(WIND[2] - 1, WIND[3] - 1);
      ft_putchar_fd('\n', 2);
      v = -1;
      while (MATR[++v])
      { w = -1;
        while (++w < coucou->mat_size)
        { ft_putchar_fd(MATR[v][w].c, 2); }
        ft_putchar_fd('$', 2);
        ft_putchar_fd('\n', 2); }
      ft_putchar('\n');
      do_exit(coucou); }

    if (*buf == 'u')
    { int v;
      int w;
      go_to(WIND[2] - 1, WIND[3] - 1);
      ft_putchar_fd('\n', 2);
      v = -1;
      while (MAPP[++v])
      { w = -1;
        while (MAPP[v][++w])
        { ft_putstr_fd("map[", 2);
          ft_putnbr_fd(MAPP[v][w]->coord[0], 2);
          ft_putstr_fd("][", 2);
          ft_putnbr_fd(MAPP[v][w]->coord[1], 2);
          ft_putstr_fd("]::", 2);
          ft_putendl_fd(MAPP[v][w]->name, 2); }
        ft_putchar_fd('$', 2);
        ft_putchar_fd('\n', 2); }
      ft_putchar('\n');
      do_exit(coucou); }

    if (*buf == 'i')
    {
      ft_putchar('\n');
      ft_putstr("SIZE::");
      ft_putnbr(SIZE);
      ft_putstr(", mat_size::");
      ft_putnbr(coucou->mat_size);
      ft_putchar('\n');
      do_exit(coucou);
    }

----------------------------------------- */
