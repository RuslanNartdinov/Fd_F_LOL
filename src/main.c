#include "fd_f.h"
//gcc src/*.c helpers/*.c minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
//./a.out test_maps/42.fdf   

int	deal_key(int key, t_fdf *data)
{
	printf("%d\n", key);
	if (key >= 123 && key <= 126)
		shift_xy(data, key);
	if (key == 24 || key == 27)
		change_z(data, key);
	if (key == 53)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (key == 43 || key == 47)
		rotate(data, key);
	if (key == 41 || key == 39)
		zoom(data, key);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_map(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20 + argc - argc;
	data->scale = 0.8;
	data->shift_x = 500;
	data->shift_y = 500;
	draw_map(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
