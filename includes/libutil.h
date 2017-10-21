/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutil.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 14:43:57 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/14 14:43:58 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUTIL_H
# define LIBUTIL_H

# include "inttypes.h"
# include "string.h"

int		ft_atoi(char const *s);
char	*ft_ctrim(char const *s, char c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isws(int c);
char	*ft_itoa(int n);
#endif
