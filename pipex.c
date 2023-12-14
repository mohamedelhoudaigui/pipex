/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:49:17 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/14 02:56:17 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av)
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
		char 	*exec_args[] = {NULL, NULL, NULL};
		char 	*exec_args2[] = {NULL, NULL, NULL};

		if (mini_parser(av[2], av[3]) == 1)
			return (1);
		input = open(av[1], O_RDWR, 0600);
		output = open(av[4], O_RDWR, 0600);
		str = check_command(av[2]);
		str2 = check_command(av[3]);
		if (error_handler(input, output, fd, str, str2) == 1)
			return (1);
		exec_args[0] = str[0];
		exec_args2[0] = str2[0];
		if (str[1] != NULL)
			exec_args[1] = str[1];
		if (str2[1] != NULL)
			exec_args2[1] = str2[1];
		pid = fork();
		if (check_pid(pid) == 1)
			return (1);
		if (pid == 0)
		{
			close(fd[0]);
			dup2(fd[1], 1);
			dup2(input, 0);
			close(fd[1]);
			close(input);
			execve(exec_args[0], exec_args, NULL);
			perror("execve");
			free_dpointer(str, str2);
		}
		pid2 = fork();
		if (check_pid(pid2) == 1)
			return (1);
		if (pid2 == 0)
		{
			close(fd[1]);
			dup2(fd[0], 0);
			dup2(output, 1);
			close(fd[0]);
			close(output);
			execve(exec_args2[0], exec_args2, NULL);
			perror("execve");
			free_dpointer(str, str2);
		}
		close(fd[0]);
		close(fd[1]);
		close(input);
		close(output);
		waitpid(pid, NULL, 0);
		waitpid(pid2, NULL, 0);
		free_dpointer(str, str2);
    }
	else
	{
		ft_printf("usage : infile cmd1 cmd2 outfile\n");
		return (1);
	}
    return (0);
}