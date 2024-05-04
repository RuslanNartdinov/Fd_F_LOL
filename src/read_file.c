#include "fd_f.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	printf("\n------------GET_HEIGHT------------\n");
	printf("Getting height...\n");
	printf("File descriptor: %d\n", fd);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		printf("The line is: %s\n", line);
		if (line == NULL || !line)
			break ;
		height++;
		free(line);
	}
	close(fd);
	printf("\n------------GET_HEIGHT------------\n");
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
	printf("\n------------GET_WIDTH------------\n");
	printf("Getting width...\n");
	printf("File descriptor: %d\n", fd);
	printf("The line is: %s\n", line);
	splitted_line = ft_split(line, ' ');
	free(line);
	width = 0;
	while (splitted_line[width])
		width++;
	while(1){
		line = get_next_line(fd);
		if(!line)
			break;
		free(line);
	}
	printf("The length of the line is: %d\n", width);
	free_split(splitted_line);
	close(fd);
	printf("------------GET_WIDTH------------\n\n");
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		iter;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	iter = 0;
	while (iter <= data->height)
		data->z_matrix[iter++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	iter = 0;
	printf("\n------------FILLING_Z-MATRIX------------\n");
	while (1)
	{
		line = get_next_line(fd);
		printf("the line is: %s\n", line);
		if (!line)
		{
			free(line);
			break ;
		}
		fill_matrix(data->z_matrix[iter], line);
		free(line);
		iter++;
	}
	data->z_matrix[iter] = NULL;
	printf("\n------------FILLING_Z-MATRIX------------\n");
	close(fd);
}
