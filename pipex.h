/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:50:08 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/14 08:35:04 by mel-houd         ###   ########.fr       */
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
# include "./libft/get_next_line.h"
# include "./libft/printf/ft_printf.h"

int		check_only_spaces(char *str);
int		mini_parser(char *command1, char *command2);
char	**check_command(char *command);

int		error_handler(int infile, int outfile, int *fd_pipe, char **com1, char **com2);
int		check_pid(int pid, int pid2);
void	free_dpointer(char	**com1, char **com2, char **exec1, char **exec2);

void	init_variables(int *input, int *output, char **com1, char **com2, char ***exec_args1, char ***exec_args2, char **av);

void	process_job(int *fd, char **exec_args, int inout, char str);

#endif