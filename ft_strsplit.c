/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:14:32 by tmckinno          #+#    #+#             */
/*   Updated: 2017/06/08 21:17:03 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_splitcnt(char const *s, char c)
{
	char	*pos;
	int		count;

	pos = ft_ctrim(s, c);
	if (pos == NULL)
		return (-1);
	count = 0;
	while (*pos)
	{
		if (*pos == c)
		{
			count++;
			pos++;
			while (*pos == c)
				pos++;
		}
		pos++;
	}
	return (count + 1);
}

char		**ft_strsplit(char const *s, char c)
{
	int		len;
	char	*pos;
	char	**results;
	char	**rpos;

	pos = ft_ctrim(s, c) - 1;
	ERR_CHECK(ft_splitcnt(s, c), -1);
	results = (char**)ft_memalloc(ft_splitcnt(s, c) * sizeof(char*));
	rpos = results;
	len = 0;
	while (*++pos)
	{
		if (*pos == c && len > 0)
		{
			*rpos++ = ft_strsub(pos - len, 0, len);
			NULL_GUARD(*(rpos - 1));
			len = 0;
		}
		len++;
		while (*pos == c)
			pos++;
	}
	if (len > 0)
		*rpos = ft_strsub(pos - len, 0, len);
	return (results);
}
