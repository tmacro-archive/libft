/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:40:52 by tmckinno          #+#    #+#             */
/*   Updated: 2017/11/05 12:41:05 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutil.h"
#include <stdio.h>
pthread_mutex_t *get_lock(int id)
{
	static pthread_mutex_t	locks[MAX_LOCKS + 1];

	if (id > MAX_LOCKS || id < 0)
		return (NULL);
	return (&locks[id]);
}

int				take_lock(t_lock lock, int block)
{
	// printf("Taking lock %i\n", lock);
	if (block)
		return (pthread_mutex_lock(get_lock(lock)));
	else
		return (pthread_mutex_trylock(get_lock(lock)));
}

int				release_lock(t_lock lock)
{
	return (pthread_mutex_unlock(get_lock(lock)));		
}

t_lock			create_lock(void)
{
	pthread_mutex_t	*lock;
	static	int	in_use;

	printf("%i\n", in_use);
	if (!in_use || in_use < 0)
		in_use = 1;
	if (in_use > MAX_LOCKS)
		return 0;
	lock = get_lock(in_use);
	if (lock != NULL)
		if (!pthread_mutex_init(lock, NULL))
			return (in_use++);
	return (0);
}