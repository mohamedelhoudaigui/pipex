/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:49:12 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/17 13:11:52 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' || (str[i] >= 9 && str[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}

int	mini_parser(char **av, int ac)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (i == 1)
		{
			if (av[i][0] == '\0' || av[ac - 1][0] == '\0')
			{
				ft_printf("invalid files\n");
				return (1);
			}
		}
		else if (av[i][0] == '\0' || check_only_spaces(av[i]) == 1)
		{
			ft_printf("invalid input\n");
			return (1);
		}
		i++;
	}
	return (0);
}

char	***all_commands(t_pipex *args)
{
	int		i;
	int		j;
	char	***all_command;

	all_command = (char ***)malloc(sizeof(char **) * args->ac - 3);
	if (!all_command)
		return (NULL);
	i = 0;
	while (i < args->ac - 3)
	{
		all_command[i] = check_command(args->av[i + 2], args->splited_path);
		if (!all_command[i])
		{
			i--;
			while (all_command[i])
			{
				j = 0;
				while (all_command[i] && all_command[i][j])
					free(all_command[i][j++]);
				free(all_command[i]);
				i--;
			}
			free(all_command);
			return (NULL);
		}
		i++;
	}
	all_command[i] = NULL;
	return (all_command);
}

char	**check_command(char *command, char **path_splited)
{
	char	**com;
	int		i;
	char	*str;
	char	*padded;
	int		key;

	com = ft_split(command, ' ');
	if (access(com[0], X_OK) == 0)
		return (com);
	key = 0;
	if (path_splited == NULL)
		return (NULL);
	padded = ft_strjoin("/", com[0]);
	free(com[0]);
	com[0] = padded;
	i = 0;
	while (path_splited[i])
	{
		str = ft_strjoin(path_splited[i], com[0]);
		if (access(str, X_OK) == 0)
		{
			free(com[0]);
			com[0] = str;
			key = 1;
			break ;
		}
		i++;
		free(str);
	}
	if (key == 1)
		return (com);
	i = 0;
	while (com[i])
		free(com[i++]);
	free(com);
	return (NULL);
}
