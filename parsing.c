/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:49:12 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/14 02:56:10 by mel-houd         ###   ########.fr       */
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

char	**check_command(char *command)
{
	char	**com;
	int		i;
	char	*str;
	char	*paths[7] = {"/bin/", "/sbin/", "/usr/bin/", "/usr/sbin/", "/usr/local/bin/", "/usr/local/sbin/", NULL};

	com = ft_split(command, ' ');
	i = 0;
	while (paths[i])
	{
		str = ft_strjoin(paths[i], com[0]);
		if (access(str, X_OK) == 0)
		{
			free(com[0]);
			com[0] = str;
        	return (com);
		}
		i++;
		free(str);
	}
	i = 0;
	while (com[i])
		free(com[i++]);
	free(com);
    return (NULL);
}