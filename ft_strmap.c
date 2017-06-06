/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 21:27:16 by tmckinno          #+#    #+#             */
/*   Updated: 2017/06/05 21:57:10 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*freshmeat;
	char	*begin;
	char	*pos;

	freshmeat = (char*)ft_strnew((size_t)ft_strlen((char*)s));
	if (freshmeat == (NULL))
		return (NULL);
	begin = freshmeat;
	pos = (char*)s;
	while(*pos)
		*freshmeat++ = f(*pos++);
	return (begin);
}
