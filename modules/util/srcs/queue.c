/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 07:59:37 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/30 07:59:40 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutil.h"
#include "macs.h"
#include <stdio.h>

t_queue	create_queue(void)
{
	t_queue				fresh;
	// pthread_mutexattr_t attr;
	// pthread_mutex_t	lock;

	// NULL_GUARD((lock = memalloc(sizeof(pthread_mutex_t))));
	NULL_GUARD((fresh = (t_queue)memalloc(sizeof(struct s_queue))));
	fresh->head = NULL;
	fresh->tail = NULL;
	fresh->len = 0;
	// pthread_mutexattr_init(&attr);
	// pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_NONE);
	printf("init lock %i\n", pthread_mutex_init(&fresh->lock, NULL));
	printf("create addr: %p\n", &fresh->lock);
	return (fresh);
}

t_q_elem	create_q_el(void *data)
{
	t_q_elem	fresh;

	NULL_GUARD((fresh = (t_q_elem)memalloc(sizeof(struct s_q_elem))));
	fresh->next = NULL;
	REF_INC((fresh->data = data));
	return (fresh);
}

int		enqueue(t_queue q, void *data, int block)
{
	int			fail;
	t_q_elem	el;

	if (block)
		fail = pthread_mutex_lock(&q->lock);
	else
		fail = pthread_mutex_trylock(&q->lock);
	if (!fail)
	{
		REF_INC((el = create_q_el(data)));
		if (!q->head)
		{
			q->head = el;
			q->tail = el;
		}
		else
		{
			q->tail->next = el;
			q->tail = el;
		}
		q->len++;
		pthread_mutex_unlock(&q->lock);
		return (1);
	}
	return (0);
}

void		*dequeue(t_queue q, int block)
{
	int			fail;
	t_q_elem	el;
	
	if (block)
		fail = pthread_mutex_lock(&q->lock);
	else
		fail = pthread_mutex_trylock(&q->lock);
	if (!fail)
	{
		el = NULL;
		if (q->head)
		{
			el = q->head;
			q->head = el->next;
			if (el == q->tail)
				q->tail = NULL;
			q->len--;
		}
		pthread_mutex_unlock(&q->lock);
		if (el)
		{
			REF_DEC(el->data);
			REF_DEC(el);
			return (el->data);
		};
	}
	return (NULL);
}

size_t		queue_len(t_queue q, int block)
{
	int			fail;
	size_t		len;

	if (block)
		fail = pthread_mutex_lock(&q->lock);
	else
		fail = pthread_mutex_trylock(&q->lock);
	if (!fail)
	{
		len = q->len;
		pthread_mutex_unlock(&q->lock);
		return (len);		
	}
	return (-1);
}