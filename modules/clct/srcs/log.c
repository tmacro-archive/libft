/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clct_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 13:26:35 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/24 11:01:26 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clct.h"
#include "fdict.h"

void	log_stats(t_dict r)
{
	clct_putstr("::\tclct stats\t::\n::\tsize: ");
	clct_putulong(r->size);
	clct_putstr("\t::\n::\tstored: ");
	clct_putulong(r->stored);
	clct_putstr("\t::\n::\tload: ");
	clct_putulong((unsigned long)(((float)(r->stored) / (float)(r->size)) * 10));
	clct_putstr("%\t::\n");
}

void	log_region(t_region *region)
{
	clct_putstr(":: ::\tsize: ");
	clct_putulong(region->size);
	if (region->size < 10)
		clct_putstr("\t");
	clct_putstr("\t:: ::\n");
}

int		logger(void *key, void *value, void *mem)
{
	t_region	*region;
	void		*trash;
	size_t		*memsz;

	trash = key;
	memsz = (size_t*)mem;
	region = (t_region*)value;
	*memsz = *memsz + region->size;
	return (1);
}

int		region_log(t_dict regions)
{
	size_t	allocd;

	allocd = 0;
	log_stats(regions);
	dict_iter(regions, &logger, &allocd);
	clct_putstr("::\tTotal memory allocated: ");
	clct_putulong(allocd);
	clct_putstr("\t::\n");
	return (1);
}
