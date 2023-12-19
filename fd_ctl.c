/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_ctl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:39:58 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/19 00:58:16 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_ctl(t_pipex *args, int i)
{
	int	j;

	if (i == 0)
	{
		close(args->fd[0][0]);
		j = 1;
		if (args->fd[j] != NULL)
		{
			while (j < args->ac - 4)
			{
				close(args->fd[j][0]);
				close(args->fd[j][1]);
				j++;
			}
		}
	}
	else if (i == args->ac - 4)
	{
		close(args->fd[i - 1][1]);
		j = 0;
		while (j < args->ac - 5)
		{
			close(args->fd[j][0]);
			close(args->fd[j][1]);
			j++;
		}
	}
	else
	{
		j = 0;
		while (j < args->ac - 4)
		{
			close(args->fd[i - 1][1]);
			close(args->fd[i][0]);
			if (j < i - 1 || j > i)
			{
				close(args->fd[j][0]);
				close(args->fd[j][1]);
			}
			j++;
		}
	}
}