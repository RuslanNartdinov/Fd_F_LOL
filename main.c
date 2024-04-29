#include "fd_f.h"
void change_z(fdf *data, int change){
	int i;
	int j;
	i = 0;
	while(i<data->height)
	{
		j = 0;
		while(j<data->width)
		{
			data->z_matrix[i][j] += change;
			j++;
		}
		i++;
	}
}

int deal_key(int key, fdf *data){
	printf("%d\n", key);
	if(key == 126)
		data->shift_y-=10;
	if(key == 125)
		data->shift_y+=10;
	if(key == 123)
		data->shift_x-=10;
	if(key == 124)
		data->shift_x+=10;
	if(key == 24)
		change_z(data, 10);
	if(key == 27)
		change_z(data, -10);
	if(key == 53){
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_map(data);
	return (0);
}

int main(int argc, char **argv){
	fdf *data;
	data = (fdf*)malloc(sizeof(fdf));
	read_file(argv[1],data);

	int i;
	int j;

	i = 0;
	printf("printing...\n");
	while(i < data->height){
		j = 0;
		while (j < data->width)
		{
			printf("%3d ", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("Done!\n");
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;

	draw_map(data);
	mlx_key_hook(data->win_ptr,deal_key, data);
	mlx_loop(data->mlx_ptr);
}