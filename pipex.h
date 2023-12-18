/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:50:08 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/18 21:23:02 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./libft/printf/ft_printf.h"

typedef struct s_pipex
{
	int		input;
	int		output;
	int		ac;
	pid_t	*pid;
	int		freed;
	int		**fd;
	char	**av;
	char	**env;
	char	**splited_path;
	char	***str;
	char	***exec_args;
}	t_pipex;

int		check_only_spaces(char *str);
int		mini_parser(char **av, int ac);
char	**check_command(char *command, char **path_splited);
char	***all_commands(t_pipex *args);

int		error_handler(t_pipex *args);
int		check_pid(int pid);
void	free_dpointer(t_pipex *args_add);

void	init_args(t_pipex *args);
int		init_variables(t_pipex *args, char **av, char **env, int ac);

void	process_job(t_pipex *args, int i);

char	**split_path(char **env_addrs);

t_pipex	*pipex(int ac, char **av, char **env);

#endif