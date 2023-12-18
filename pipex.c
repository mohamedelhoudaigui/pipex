/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:30:18 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/18 11:19:26 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_job(t_pipex *args, int i)
{
	if (i == 0)
	{
		ft_printf("here 1\n");
		close(args->fd[2][0]);
		close(args->fd[2][1]);
		close(args->fd[1][0]);
		close(args->fd[1][1]);
		close(args->fd[0][0]);
		dup2(args->fd[0][1], 1);
		dup2(args->input, 0);
		close(args->fd[0][1]);
		close(args->input);
		close(args->output);
		execve(args->exec_args[0][0], args->exec_args[0], NULL);
		perror("execve error");
	}
	else if (i == args->ac - 4)
	{
		ft_printf("here 3\n");
		close(args->fd[0][0]);
		close(args->fd[0][1]);
		close(args->fd[1][0]);
		close(args->fd[1][1]);
		close(args->fd[2][1]);
		dup2(args->fd[2][0], 0);
		dup2(args->output, 1);
		close(args->fd[2][0]);
		close(args->output);
		close(args->input);
		execve(args->exec_args[i][0], args->exec_args[i], NULL);
		perror("execve error");
	}
	else
	{
		ft_printf("here 2\n");
		close(args->fd[0][0]);
		close(args->fd[0][1]);
		close(args->fd[2][0]);
		close(args->fd[2][1]);
		dup2(args->fd[1][1], 1);
		dup2(args->fd[1][0], 0);
		close(args->fd[1][0]);
		close(args->fd[1][1]);
		close(args->input);
		close(args->output);
		execve(args->exec_args[i][0], args->exec_args[i], NULL);
		perror("execve error");
	}
}

void	main_helper(t_pipex *args)
{
	int	i;

	i = 0;
	close(args->fd[0][0]);
	close(args->fd[0][1]);
	close(args->fd[1][0]);
	close(args->fd[1][1]);
	close(args->fd[2][0]);
	close(args->fd[2][1]);
	close(args->input);
	close(args->output);
	while (i < args->ac - 4)
		waitpid(args->pid[i], NULL, i);
}

t_pipex	*pipex(int ac, char **av, char **env)
{
	t_pipex	*args;
	int		i;

	if (mini_parser(av, ac) == 1)
			return (NULL);
	args = (t_pipex *)malloc(sizeof(t_pipex));
	if (!args)
		return (NULL);
	if (init_variables(args, av, env, ac) == 1)
		return (args);
	i = 0;
	while (i < ac - 3)
	{
		args->pid[i] = fork();
		if (check_pid(args->pid[i]) == 1)
			return (args);
		if (args->pid[i] == 0)
			process_job(args, i);
		i++;
	}
	if (args->pid[i] != 0)
		main_helper(args);
	return (args);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*args;
	
	if (ac >= 5)
	{
		args = pipex(ac, av, env);
		if (args == NULL)
			return (1);
		else
		{
			free_dpointer(args);
			free(args);
			return (0);
		}
	}
	else
	{
		ft_printf("usage : infile cmd1 cmd2 outfile\n");
		return (1);
	}
	return (0);
}
