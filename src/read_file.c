#include "fd_f.h"

t_fdf	*struct_init(char *argv_1)
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->win_width = 1000;
	data->win_length = 1000;
	data->zoom = 10;
	data->scale = 0.8;
	data->shift_x = 0;
	data->shift_y = 0;
	data->x = 0;
	data->y = 0;
	read_file(argv_1, data);
	return (data);
}

void	fill_matrix(int *z_line, int *color_line, char *line)
{
	char	**nums;
	char	**number;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		number = ft_split(nums[i], ',');
		if (get_length(number) == 2)
			color_line[i] = ft_atoi_base(number[1] + 2, 16);
		else if (ft_atoi(number[0]) > 0)
			color_line[i] = 0xffffff;
		else
			color_line[i] = 0xe80c0c;
		z_line[i] = ft_atoi(number[0]);
		free_split(number);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	fill_struct(char *file_name, t_fdf *data)
{
	int		iter;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	data->color_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	iter = 0;
	while (iter <= data->height)
	{
		data->z_matrix[iter] = (int *)malloc(sizeof(int) * (data->width + 1));
		data->color_matrix[iter] = (int *)malloc(sizeof(int) * \
				(data->width + 1));
		iter++;
	}
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		iter;

	fill_struct(file_name, data);
	fd = open(file_name, O_RDONLY, 0);
	iter = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		fill_matrix(data->z_matrix[iter], data->color_matrix[iter], line);
		free(line);
		iter++;
	}
	data->z_matrix[iter] = NULL;
	close(fd);
}
