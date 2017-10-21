/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 12:37:23 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/21 12:37:24 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logr.h"
#include "libio.h"

char	*lvl_to_str(int lvl)
{
	if (lvl == 0)
		return ("DEBUG");
	else if (lvl == 10)
		return ("INFO");
	else if (lvl == 20)
		return ("WARNING");
	else if (lvl == 30)
		return ("ERROR");
	else if (lvl == 40)
		return ("CRITICAL");
	return (NULL);
}

void	log_prefix(char *tag)
{
	time_t		raw;
	struct tm	*info;

	time(&raw);
	info = localtime(&raw);
	ft_putstr(":: [");
	ft_putstr(asctime(info));
	ft_putstr("] ");
	ft_putstr(tag);
	ft_putstr(" :: ");
}

void	log_msg(t_logger logr, char *msg, int lvl)
{
	log_prefix(logr->tag);
	ft_putstr(lvl_to_str(lvl));
	ft_putstr(" ");
	ft_putstr(msg);
	ft_putstr("\n");
}

void	logr(t_logger logr, char *msg, int lvl)
{
	NULL_GUARD_NR(logr);
	if (logr->level >= lvl)
		log_msg(logr, msg, lvl);
}
