/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 02:05:53 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/20 08:46:47 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		here_doc(t_pipex *args)
{
	char *str;
	int	here_doc[2];
	int	len;

	len = ft_strlen(args->av[2]);
	if (len == 0 && args->av[2][0] == '\0')
		len++;
	if (pipe(here_doc) < 0)
		return (perror("pipe"), -1);
	ft_printf("heredoc> ");
	str = get_next_line(0);
	while (ft_strncmp(str, args->av[2], len) != 0)
	{
		ft_printf("heredoc> ");
		write(here_doc[1], str, ft_strlen(str));
		free(str);
		str = get_next_line(0);
		if (str[0] == 10 && args->av[2][0] == '\0')
			break ;
	}
	free(str);
	close(here_doc[1]);
	args->input = here_doc[0];
	return (0);
}
