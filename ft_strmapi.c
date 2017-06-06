/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 22:19:10 by tmckinno          #+#    #+#             */
/*   Updated: 2017/06/05 22:30:43 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*freshmeat;
	char			*begin;
	char			*pos;
	unsigned int	index;

	freshmeat = (char*)ft_strnew((size_t)ft_strlen((char*)s));
	if (freshmeat == (NULL))
		return (NULL);
	begin = freshmeat;
	pos = (char*)s;
	index = 0;
	while (*pos)
		*freshmeat++ = f(index++, *pos++);
	return (begin);
}
