/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 00:33:12 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/22 02:51:25 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>

int (*(term_size)(void))[2]
{ struct winsize w;
  static int size[2];
  ioctl(0, TIOCGWINSZ, &w);
  size[0] = w.ws_col;
  size[1] = w.ws_row;
  return (&size); }
