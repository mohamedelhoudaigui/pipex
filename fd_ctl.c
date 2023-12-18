/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_ctl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:39:58 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/19 00:23:50 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fd_ctl(t_pipex *args, int i)
{
	int	j;

	j = 1;
	if (i == 0)
	{
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
	j = 0;
	else if (i == args->ac - 4)
	{
		while (j < args->ac - 5)
		{
			close(args->fd[j][0]);
			close(args->fd[j][1]);
			j++;
		}
	}
	j = 0;
	else
	{
		while (j < args->ac - 5)
		{
			close(args->fd[j][0]);
			close(args->fd[j][1]);
			j++;
		}
	}
}