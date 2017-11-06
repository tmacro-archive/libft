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
# include <pthread.h>
# include "clct.h"


# define MAX_LOCKS 1024

struct s_queue;
struct s_q_elem;

typedef struct s_queue  *t_queue;
typedef struct s_q_elem *t_q_elem;
typedef int				t_lock;

struct					s_queue
{
	pthread_mutex_t		lock;
	t_q_elem			head;
	t_q_elem			tail;
	size_t				len;
};

struct					s_q_elem
{
	t_q_elem			next;
	void				*data;
};

int						ft_atoi(char const *s);
char					*ft_ctrim(char const *s, char c);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
int						ft_isws(int c);
char					*ft_itoa(int n);
t_queue 				create_queue(void);
int						enqueue(t_queue q, void *data, int block);
void					*dequeue(t_queue q, int block);
pthread_mutex_t			*get_lock(int id);
int						take_lock(t_lock lock, int block);
int						release_lock(t_lock lock);
t_lock					create_lock(void);
#endif
