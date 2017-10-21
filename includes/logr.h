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

struct					s_logger
{
	char	*tag;
	int		level;
};

typedef struct s_logger	*t_logger;

t_logger				get_logger(char *tag, int lvl);
void					logr(t_logger logr, char *msg, int lvl);
#endif
