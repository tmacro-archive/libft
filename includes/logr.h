/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 12:33:46 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/21 12:33:47 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGR_H
# define LOGR_H

# include <time.h>
# include "libmem.h"

#ifndef DEFAULT_LOGGER
# define DEFAULT_LOGGER "logr"
#endif

# define LOG(msg, lvl) (logr(get_logger(DEFAULT_LOGGER, 0), msg, lvl))
# define DEBUG(msg) LOG(msg, 0)
# define INFO(msg) LOG(msg, 10)
# define WARN(msg) LOG(msg, 20)
# define ERROR(msg) LOG(msg, 30)
# define CRIT(msg) LOG(msg, 40)

struct					s_logger
{
	char	*tag;
	int		level;
};

typedef struct s_logger	*t_logger;

t_logger				get_logger(char *tag, int lvl);
void					logr(t_logger logr, char *msg, int lvl);
#endif
