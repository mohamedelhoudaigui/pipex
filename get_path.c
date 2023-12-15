#include "pipex.h"

char	**split_path(char ***env_addrs)
{
	int		i;
	char	*PATH;
	char	**splited_PATH;
	char	**env;

	i = 0;
	env = *env_addrs;
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
