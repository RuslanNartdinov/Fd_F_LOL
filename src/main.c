#include "fd_f.h"
//gcc src/*.c helpers/*.c minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
//./a.out test_maps/42.fdf   

void clean_struct(t_fdf *data){
	if (data)
    {
        if (data->z_matrix)
        {
            for (int i = 0; i < data->height; i++)
            {
                free(data->z_matrix[i]);
            }
            free(data->z_matrix);
        }
        free(data);
    }
}

int	deal_key(int key, t_fdf *data)
{
	printf("%d\n", key);
	if (key >= 123 && key <= 126)
		shift_xy(data, key);
	if (key == 24 || key == 27)
		change_z(data, key);
	if (key == 53)
	{
		mlx_destroy_image(data->mlx_ptr,data->mlx.img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		clean_struct(data);
		exit(0);
	}
	if (key == 43 || key == 47)
		rotate(data, key);
	if (key == 41 || key == 39)
		zoom(data, key);
	mlx_destroy_image(data->mlx_ptr,data->mlx.img);
	mlx_clear_window(data->mlx_ptr,data->win_ptr);
	data->mlx.img = mlx_new_image(data->mlx_ptr, data->img_width, data->img_length);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel, &data->mlx.line_length, &data->mlx.endian);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx.img, data->x, data->y);
	return (0);
}

void print_map(t_fdf *data)
{
	int i = 0;
	int j;
	printf("height: %d, width: %d\n", data->height, data->width);
	while(i < data->height)
	{
		j = 0;
		while(j < data->width)
		{
			printf("%d ", (data->z_matrix)[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int close_win(t_fdf* data)
{
	mlx_destroy_image(data->mlx_ptr,data->mlx.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	clean_struct(data);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	(void)argc;
	data = (t_fdf *)malloc(sizeof(t_fdf));
	//print_map(data);
	data->win_width = 1000;
	data->win_length = 1000;
	data->img_width = 1000;
	data->img_length = 1000;
	data->zoom = 10;
	data->scale = 0.8;
	data->shift_x = 0;
	data->shift_y = 0;
	data->x = 0;
	data->y = 0;

	read_file(argv[1], data);

	if(data->height > 100 || data->width > 100)
	{
		data->zoom = 5;
	}

	printf("Printing colors...\n");
	for(int i = 0; i < data->height; i++){
		for(int j = 0; j < data->height; j++){
			printf("%d ",data->color_matrix[i][j]);
		}
		printf("\n");
	}
	
	
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width, data->win_length, "FDF");
	data->mlx.img = mlx_new_image(data->mlx_ptr, data->img_width, data->img_length);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel, &data->mlx.line_length, &data->mlx.endian);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx.img, data->x, data->y);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, 1L<<0, close_win, data);
	mlx_loop(data->mlx_ptr);
	clean_struct(data);
	return (0);
}
