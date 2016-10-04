/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_coucou.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 09:45:45 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/15 08:37:01 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"
#include <stdlib.h>

void free_coucou(t_term *coucou)
{ free_matrix(coucou->matrix);
  free_mapper(coucou);
  free(coucou->tab_tri); }
