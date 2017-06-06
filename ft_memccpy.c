/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 15:20:27 by tmckinno          #+#    #+#             */
/*   Updated: 2017/06/05 20:43:03 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*src;
	size_t			len;
	len = 0;
	src = (unsigned char*)s2;
	printf("--------------------------------------------------------------\n");
	while (len < n)
	{
		len++;
		printf("\n%u - %u",*src, (unsigned char)c);
		if ((unsigned char)*src == (unsigned char)c)
		{
			printf("--------------------------------------------------------------\n");
			printf("%p - %i\n",src, c);
			break ;
		}
		src++;
	}
	ft_memcpy(s1, s2, len);
	if (len == n)
		return (NULL);
	return (s1 + len);
}
