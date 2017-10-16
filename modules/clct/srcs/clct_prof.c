/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clct_prof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 13:47:48 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/18 16:18:43 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clct.h"

void	*prof_manu
void prof_start(char *tag, int line, char *file)
{
	static t_profile	**profiles;
	static size_t		depth;
	t_profile			tmp;

	if (!profiles)
	{
		profiles = malloc(sizeof(t_profile*) * PROF_MAX_DEPTH);
		depth = 0;
	}
	tmp = (t_profile*)malloc(sizeof(t_profile));
	if (!tmp)
		return ;
	tmp->tag = tag;
	tmp->file = file;
	tmp->line = line;
	tmp->start = microtime();
	depth++;
	profiles[depth] = tmp;	
}

void	prof_end()
{

}
