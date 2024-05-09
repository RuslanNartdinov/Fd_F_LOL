#include "fd_f.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || !line)
			break ;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

void	free_split(char **splitted_arr)
{
	char	**dup_link;

	dup_link = splitted_arr;
	if (!splitted_arr)
	{
		while (splitted_arr)
		{
			free(*splitted_arr);
			splitted_arr++;
		}
		free(dup_link);
	}
}

int	get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;
	char	**splitted_line;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	splitted_line = ft_split(line, ' ');
	free(line);
	width = 0;
	while (splitted_line[width])
		width++;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
	free_split(splitted_line);
	close(fd);
	return (width);
}

int	get_length(char **splitted_line)
{
	int	size;

	size = 0;
	while (splitted_line[size])
		size++;
	return (size);
}
