#include "pipex.h"

char	**split_path(char **env)
{
	int		i;
	char	*PATH;
	char	**splited_PATH;

	i = 0;
	if (env[i] == NULL)
		return (NULL);
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 6))
			break ;
		i++;
	}
	PATH = ft_strtrim(env[i], "PATH=");
	if (!PATH)
		return (NULL);
	splited_PATH = ft_split(PATH, ':');
	if (!splited_PATH)
	{
		free(PATH);
		return (NULL);
	}
	free(PATH);
	return (splited_PATH);
}
