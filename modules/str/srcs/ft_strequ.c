/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:32:57 by tmckinno          #+#    #+#             */
/*   Updated: 2017/06/11 13:11:58 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"
#include "libmem.h"

int	ft_strequ(char const *s1, char const *s2)
{
	ERR_CNR(s1, NULL, 0);
	ERR_CNR(s2, NULL, 0);
	return (ft_strcmp(s1, s2) == 0);
}
