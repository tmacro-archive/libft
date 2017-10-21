/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 12:36:01 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/21 12:36:02 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdict.h"
#include "logr.h"
#include "clct.h"
#include "libstr.h"

t_logger	create_logger(char *tag, int lvl)
{
	t_logger logr;

	NULL_GUARD((logr = memalloc(sizeof(struct s_logger))));
	logr->tag = ft_strdup(tag);
	logr->level = lvl;
	return (logr);
}

t_logger	get_logger(char *tag, int lvl)
{
	static t_dict		loggers;
	t_logger			logr;

	if (!loggers)
		loggers = SDICT;
	logr = DGET(loggers, tag);
	if (logr)
		return (logr);
	logr = create_logger(tag, lvl);
	DSET(loggers, tag, logr);
	return (logr);
}
