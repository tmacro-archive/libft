/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 12:41:27 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/21 12:41:29 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clct.h"

size_t	clct_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

void	clct_putulong_fd(unsigned long n, int fd)
{
	char	c;

	c = (n % 10) + 48;
	n /= 10;
	if (n > 0)
		clct_putulong_fd(n, fd);
	write(fd, &c, 1);
}

void	clct_putulong(unsigned long n)
{
	clct_putulong_fd(n, 1);
}

void	clct_putstr_fd(char const *s, int fd)
{
	write(fd, s, clct_strlen((char*)s));
}

void	clct_putstr(char const *s)
{
	clct_putstr_fd(s, 1);
}
