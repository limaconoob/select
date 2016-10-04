/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 04:49:23 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/22 02:50:54 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <signal.h>

static void mutter_sig(int sig)
{ if (sig == SIGWINCH)
  { get_size(term_size(), NULL);
    term_init(sig, NULL); }
  else if (sig == SIGTSTP || sig == SIGINT || sig == SIGCONT)
  { term_init(sig, NULL); }}

void ft_signal(void)
{ signal(SIGWINCH, mutter_sig);
  signal(SIGTSTP, mutter_sig);
  signal(SIGINT, mutter_sig);
  signal(SIGQUIT, mutter_sig);
  signal(SIGCONT, mutter_sig); }
