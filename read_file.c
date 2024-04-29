#include "fd_f.h"

int get_height(char *file_name){
	char *line;
	int fd;
	int height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	printf("getting height...");
	while((line = get_next_line(fd))){
		height++;
		free(line);
	}
	printf("Done!\n");
	close(fd);
	return (height);
}

void free_split(char** splitted_arr){
	printf("freeing split...");
	char **dup_link = splitted_arr;
	if(!splitted_arr){
		while(splitted_arr){
			free(*splitted_arr);
			splitted_arr++;
		}
		free(dup_link);
	}
	printf("Done!\n");
}

int get_width(char *file_name){
	char *line;
	int fd;
	int width;
	char** splitted_line;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	splitted_line = ft_split(line, ' ');
	free(line);
	printf("getting width..");
	width = 0;
	while(splitted_line[width])
		width++;
	printf("Done!\n");
	free_split(splitted_line);
	close(fd);
	return (width);
}

void fill_matrix(int *z_line, char* line){
	char **nums;
	int i;
	nums = ft_split(line, ' ');

	i = 0;
	while(nums[i]){
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void read_file(char *file_name, fdf *data){
	int fd;
	char *line;
	int iter;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int**)malloc(sizeof(int*) * (data->height + 1));
	iter = 0;
	printf("filling matrix...");
	while (iter<=data->height){
		data->z_matrix[iter++] = (int *)malloc(sizeof(int) * (data->width + 1));
	}
	fd = open(file_name, O_RDONLY, 0);
	iter = 0;
	while((line = get_next_line(fd))){
		fill_matrix(data->z_matrix[iter], line);
		free(line);
		iter++;
	}
	printf("Done!\n");
	data->z_matrix[iter] = NULL;
	close(fd);
}