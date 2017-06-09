/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:40:58 by tmckinno          #+#    #+#             */
/*   Updated: 2017/06/07 17:47:46 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*pos;
	char	*freshmeat;

	freshmeat = ft_strnew(len);
	if (freshmeat == NULL)
		return (NULL);
	pos = (char*)s + start;
	ft_strncpy(freshmeat, pos, len);
	return (freshmeat);
}
