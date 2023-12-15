/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:49:17 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/15 01:36:26 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_job(int *fd, char **exec_args, int inout, char str)
{
	if (str == 'i')
	{
		close(fd[0]);
		dup2(fd[1], 1);
		dup2(inout, 0);
		close(fd[1]);
		close(inout);
		execve(exec_args[0], exec_args, NULL);
		perror("execve");
		
	}
	else if (str == 'o')
	{
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(inout, 1);
		close(fd[0]);
		close(inout);
		execve(exec_args[0], exec_args, NULL);
		perror("execv");
	}
}

void	main_helper(int *fd, int input, int output)
{
	close(fd[0]);
	close(fd[1]);
	close(input);
	close(output);
}

int main(int ac, char **av, char **env)
{
    if (ac == 5)
    {
        int 	input;
        int		output;
		char	**str;
		char	**str2;
		int		fd[2];
		int		pid;
		int		pid2;
		char 	**exec_args;
		char 	**exec_args2;
		char	**splited_path;

		if (mini_parser(av[2], av[3]) == 1)
			return (1);
		splited_path = split_path(&env);
		str = check_command(av[2], splited_path);
		str2 = check_command(av[3], splited_path);
		init_variables(&input, &output, str, str2, &exec_args, &exec_args2, av);
		if (error_handler(input, output, fd, str, str2) == 1)
			return (1);
		pid = fork();
		if (pid == 0)
			process_job(fd, exec_args, input, 'i');
		pid2 = fork();
		if (check_pid(pid, pid2) == 1)
			return (1);
		if (pid2 == 0)
			process_job(fd, exec_args2, output, 'o');
		if (pid != 0 && pid2 != 0)
		{
			main_helper(fd, input, output);
			waitpid(pid, NULL, 0);
			waitpid(pid2, NULL, 0);
			free_dpointer(str, str2, exec_args, exec_args2);
		}
    }
	else
	{
		ft_printf("usage : infile cmd1 cmd2 outfile\n");
		return (1);
	}
    return (0);
}