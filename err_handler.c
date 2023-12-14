/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:51:55 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/14 07:51:13 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		error_handler(int infile, int outfile, int *fd_pipe, char **com1, char **com2)
{
	if (infile == -1 || outfile == -1)
	{
		ft_printf("problem in generating fd or invalid files\n");
		return (1);
	}
	if (pipe(fd_pipe) == -1)
	{
		perror("pipe error\n");
		close(infile);
		close(outfile);
		return (1);
	}
	if (com1 == NULL || com2 == NULL)
	{
		ft_printf("malloc fail or command not found !\n");
		close(infile);
		close(outfile);
		return (1);
	}
	return (0);
}

int		check_pid(int pid, int pid2)
{
	if (pid == -1 || pid2 == -1)
	{
		perror("fork error\n");
		return (1);
	}
	return (0);
}

void	free_dpointer(char	**com1, char **com2, char **exec1, char **exec2)
{
	int	i;
	free(com1);
	free(com2);
	i = 0;
	while (exec1[i])
		free(exec1[i++]);
	free(exec1);
	i = 0;
	while (exec2[i])
		free(exec2[i++]);
	free(exec2);
}