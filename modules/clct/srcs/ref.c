/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clct_ref.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 11:02:05 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/24 11:15:32 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clct.h"

int	ref_inc(t_dict regions, void *key)
{
	t_region	*tmp;

	tmp = DGET(regions, key);
	if (tmp)
		return (++(tmp->ref_count));
	return (-1);
}

int	ref_dec(t_dict regions, void *key)
{
	t_region	*tmp;

	tmp = DGET(regions, key);
	if (tmp)
		if (tmp->ref_count > 0)
			return (--(tmp->ref_count));
	return (0);
}

int	ref_sweep(t_dict regions)
{
	size_t		i;
	t_fdict_el	**prev;
	t_fdict_el	*e;
	t_region	*tmp;

	i = 0;
	while (i < regions->size)
	{
		prev = &(regions->buckets[i++]);
		while (*prev)
		{
			tmp = (t_region*)(*prev)->value;
			if (tmp->ref_count <= 0)
			{
				e = *prev;
				*prev = e->next;
				FREE_DUO(tmp->address, tmp);
				free(e);
				regions->stored--;
				continue ;
			}
			prev = &((*prev)->next);
		}
	}
	return (1);
}

int	cleaner(void *key, void *value, void *freed)
{
	t_region	*tmp;
	size_t		*frd;
	void		*nil;

	nil = key;
	frd = (size_t*)freed;
	tmp = (t_region*)value;
	free(tmp->address);
	*frd = *frd + tmp->size;
	free(tmp);
	return (1);
}

int	ref_clean(t_dict regions)
{
	size_t	freed;

	dict_iter(regions, &cleaner, &freed);
	return (1);
}
