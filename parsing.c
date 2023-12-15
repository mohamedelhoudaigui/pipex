/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:49:12 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/15 01:36:20 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		check_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int		mini_parser(char *command1, char *command2)
{
	int	s1;
	int	s2;

	s1 = 0;
	s2 = 0;
	if (command1[0] == '\0' || command2[0] == '\0')
	{
		ft_printf("invalid input\n");
		return (1);
	}
	if (check_only_spaces(command1) == 1 || check_only_spaces(command2) == 1)
	{
		ft_printf("invalid input\n");	
		return (1);
	}
	return (0);
}

char	**check_command(char *command, char **path_splited)
{
	char	**com;
	int		i;
	char	*str;

	if (path_splited == NULL)
		return (NULL);
	com = ft_split(command, ' ');
	com[0] = ft_strjoin("/", com[0]);
	i = 0;
	while (path_splited[i])
	{
		str = ft_strjoin(path_splited[i], com[0]);
		if (access(str, X_OK) == 0)
		{
			free(com[0]);
			com[0] = str;
        	return (com);
		}
		i++;
		free(str);
	}
    return (NULL);
}