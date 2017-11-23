/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clct_region.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 15:14:19 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/18 15:10:10 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clct.h"
#include "macs.h"

int	region_manip_inner(void *addr, int mode, size_t len)
{
	static t_dict 			regions;

	if (!regions)
		regions = VDICT;
	IF_RET((RM_ALLC == mode), region_add(regions, addr, len));
	IF_RET((RM_FREE == mode), region_rem(regions, addr));
	IF_RET((RM_RINC == mode), ref_inc(regions, addr));
	IF_RET((RM_RDEC == mode), ref_dec(regions, addr));
	IF_RET((RM_RSWP == mode), ref_sweep(regions));
	IF_RET((RM_RLOG == mode), region_log(regions));
	if (RM_RCLN == mode)
	{
		ref_clean(regions);
		dict_destroy(regions);
		regions = NULL;
		return (1);
	}
	return (-1);
}

int	region_manip(void *addr, int mode, size_t len)
{
	static pthread_mutex_t	lock;
	static int				flag;
	int						ret;

	if (!flag)
	{
		pthread_mutex_init(&lock, NULL);
		flag = 1;
	}
	pthread_mutex_lock(&lock);
	if (mode == RM_RNEW)
	{
		ret = region_manip_inner(addr, RM_ALLC, len);
		ret = region_manip_inner(addr, RM_RINC, 0);
	}
	else
		ret = region_manip_inner(addr, mode, len);
	pthread_mutex_unlock(&lock);
	return (ret);
}
int	region_add(t_dict regions, void *addr, size_t len)
{
	t_region *new;

	new = (t_region*)malloc(sizeof(t_region));
	if (new == NULL)
		return (0);
	new->address = addr;
	new->size = len;
	new->ref_count = 0;
	DSET(regions, addr, new);
	return (1);
}

int	region_rem(t_dict regions, void *addr)
{
	t_region	*tmp;

	tmp = DGET(regions, addr);
	if (tmp)
	{
		DREM(regions, addr);
		free(tmp);
	}
	return (0);
}
