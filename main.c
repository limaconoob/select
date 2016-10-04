/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 01:36:31 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/20 02:26:59 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

int main(int argc, char **argv)
{ t_term *coucou;
  if (argc == 1)
  { select_error(MissingArgument, "./ft_select"); }
  ft_signal();
  term_init();
  coucou = coucou_init();
  get_names(argv, coucou);
  matrix_init(coucou);
  init_slide(coucou);
  init_wind(WIND, MATR, coucou);
  windower(WIND, MATR);
  command_line(coucou);
  term_init();
  put_result(coucou);
  free_coucou(coucou);
  return (0); }
