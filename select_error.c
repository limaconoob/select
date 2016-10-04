/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:41:51 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/12 03:37:10 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"
#include <stdlib.h>
#include <sysexits.h>

static void		msg(char *msg, int exit_code)
{
	ft_putendl_fd(msg, 2);
	exit(exit_code);
}

void			select_error(int type, char *prob)
{
	ft_putstr_fd("Fehler: ", 2);
	ft_putstr_fd(prob, 2);
	if (type == MissingFile)
		msg(": Kein Datei oder Ordner", EX_OSFILE);
	else if (type == Access)
		msg(": Zugang ist verboten", EX_NOPERM);
	else if (type == MissingArgument)
		msg(": Brauch Argumente", EX_USAGE);
	else if (type == Malloc)
		msg(": Malloc dürft nicht Gedächtnis zu behalten", EX_OSERR);
	else if (type == TermInit)
		msg(": Die Handhaben über /dev/tty ist nicht verfügbar", EX_CONFIG);
	exit(EXIT_FAILURE);
}
