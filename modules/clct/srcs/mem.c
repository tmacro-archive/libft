/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 15:50:41 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/05 13:44:26 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clct.h"

void	*memalloc(size_t len)
{
	void			*freshmeat;

	freshmeat = (void*)malloc(len);
	if (freshmeat == NULL)
		return (NULL);
	region_manip(freshmeat, RM_ALLC, len);
	return (freshmeat);
}

void	*memalloc_inc(size_t len)
{
	void			*freshmeat;

	freshmeat = (void*)malloc(len);
	if (freshmeat == NULL)
		return (NULL);
	region_manip(freshmeat, RM_RNEW, len);
	return (freshmeat);
}

int		memfree(void **addr)
{
	if (addr && region_manip(*addr, RM_FREE, 0) == 1)
	{
		free(*addr);
		*addr = NULL;
		return (1);
	}
	return (0);
}
