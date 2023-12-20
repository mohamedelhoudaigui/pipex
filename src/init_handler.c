/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:31:06 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/20 04:27:37 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_args(t_pipex *args)
{
	int	i;

	if (args->str == NULL)
	{
		args->exec_args = NULL;
		return ;
	}
	args->exec_args = (char ***)ft_calloc(sizeof(char **), args->ac - 2);
	if (!args->exec_args)
		return ;
	i = 0;
	while (args->str[i])
	{
		args->exec_args[i] = args->str[i];
		i++;
	}
	args->exec_args[i] = NULL;
}

void	init_pipes(t_pipex *args)
{
	int	i;

	i = 0;
	args->fd = (int **)ft_calloc(sizeof(int *), args->ac - 3);
	if (!args->fd)
		return ;
	while (i < args->ac - 4)
	{
		args->fd[i] = (int *)ft_calloc(sizeof(int), 2);
		pipe(args->fd[i]);
		i++;
	}
}

void	init_pid(t_pipex *args)
{
	args->pid = (pid_t *)malloc(sizeof(int) * args->ac - 3);
	if (!args->pid)
		return ;
}

void	change_av(t_pipex *args)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	args->change_av = (char **)ft_calloc(sizeof(char *), args->ac - 1);
	if (!args->change_av)
		return ;
	while (args->av[i])
	{
		if (i == 2)
			i++;
		args->change_av[j] = args->av[i];
		j++;
		i++;
	}
}

int	init_variables(t_pipex *args, char **av, char **env, int ac)
{
	args->freed = 0;
	args->av = av;
	args->ac = ac;
	args->env = env;
	args->change_av = NULL;
	args->splited_path = split_path(env);
	if (here_doc_parse(av) == 0)
	{
		if (here_doc(args)!= 0)
			return (1);
		change_av(args);
		args->av = args->change_av;
		args->ac = args->ac - 1;
	}
	else
		args->input = open(av[1], O_RDWR | O_CREAT, 0777);
	args->str = all_commands(args);
	args->output = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	init_pipes(args);
	init_args(args);
	init_pid(args);
	if (error_handler(args) == 1)	
		return (1);
	return (0);
}
