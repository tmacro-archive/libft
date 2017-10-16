/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 11:33:25 by tmckinno          #+#    #+#             */
/*   Updated: 2017/06/09 13:54:44 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

size_t	ft_strlen_d(char const *s, char delim)
{
	char	*pos;
	size_t	len;

	pos = (char*)s;
	len = 0;
	while (*pos && *pos != delim)
	{
		pos++;
		len++;
	}
	return (len);
}
