/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:48:28 by tmckinno          #+#    #+#             */
/*   Updated: 2017/06/07 17:54:24 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*freshmeat;

	len = ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1;
	freshmeat = ft_strnew(len);
	if (freshmeat == NULL)
		return (NULL);
	ft_strcat(freshmeat, s1);
	ft_strcat(freshmeat, s2);
	return (freshmeat);
}
