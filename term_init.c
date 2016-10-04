/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 02:33:13 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/27 07:53:45 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"
#include <sys/ioctl.h>
#include <termios.h>

static void mouse_use(void)
{ static int mouse_flag = 0;
  if (!mouse_flag)
  { ft_putstr_fd("\033[?1000h\x1b[?1002h\x1b[?1015h\x1b[?1006h", 2);
    mouse_flag = 1; }
  else
  { ft_putstr_fd("\033[?1006l\x1b[?1015l\x1b[?1002l\x1b[?1000l", 2);
    mouse_flag = 0; }}

void term_init(int sig, t_term *coucou)
{ struct termios term;
  static t_term *stock;
  if (!sig && coucou)
  { stock = coucou;
    return ; }
  else if (sig == 28)
  { windower(stock);
    return ; }
  else if (sig == 19)
  { init_wind(stock);
    windower(stock); }
	if (ioctl(0, TIOCGETA, &term) == -1)
  { select_error(TermInit, "TermKappa"); }
	term.c_lflag ^= ~(ICANON);
	term.c_lflag ^= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (ioctl(0, TIOCSETA, &term) == -1)
  { select_error(TermInit, "TermKappa"); }
  mouse_use(); }
