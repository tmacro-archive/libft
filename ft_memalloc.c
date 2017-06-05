/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 09:11:05 by tmckinno          #+#    #+#             */
/*   Updated: 2017/06/05 09:44:44 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh;
	int		*pos;

	fresh = malloc(size);
	if (fresh == NULL)
	{
		return (NULL);
	}
	pos = fresh;
	while (size > 0)
	{
		*pos = 0;
		pos++;
	}
	return (fresh);
}
