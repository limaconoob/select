/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 01:36:31 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/28 06:49:49 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"
#include <stdlib.h>

int main(int argc, char **argv)
{ t_term *coucou;
  if (argc == 1)
  { select_error(MissingArgument, "./ft_select"); }
  ft_signal();
  term_init(0, NULL);
  coucou = coucou_init();
  get_names(argv, coucou);
  matrix_init(coucou);
  init_slide(coucou);
  put_window(coucou, NULL);
  command_line(coucou);
  term_init(0, NULL);
  put_result(coucou);
  free_coucou(coucou);
  return (0); }
