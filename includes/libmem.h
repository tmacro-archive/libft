/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 14:38:47 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/14 14:38:49 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMEM_H
# define LIBMEM_H
# include <string.h>
# include <stdlib.h>

# define NULL_GUARD(val)  if (val == NULL) return NULL
# define NULL_GUARD_NR(val) if (val == NULL) return
# define ERR_CHECK(val, err) if (val == err) return NULL
# define ERR_CNR(val, err, ret) if (val == err) return (ret)

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
#endif
