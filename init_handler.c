/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:31:06 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/14 07:58:19 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_variables(int *input, int *output, char **com1, char **com2, char ***exec_args1, char ***exec_args2, char **av)
{
	char	**exec1;
	char	**exec2;

	if (com1 == NULL || com2 == NULL)
		return ;
	exec1 = (char **)malloc(sizeof(char *) * 3);
	exec2 = (char **)malloc(sizeof(char *) * 3);
	if (!exec1 || !exec2)
		return ;
	*exec_args1 = exec1;
	*exec_args2 = exec2; 
	*input = open(av[1], O_RDWR | O_CREAT, 0777);
	*output = open(av[4], O_RDWR | O_CREAT, 0777);
	exec1[0] = com1[0];
	exec2[0] = com2[0];
	exec1[1] = NULL;
	exec2[1] = NULL;
	exec1[2] = NULL;
	exec2[2] = NULL;
	if (com1[1] != NULL)
		exec1[1] = com1[1];
	if (com2[1] != NULL)
		exec2[1] = com2[1];
}