#include "fd_f.h"

void	add_zoom(float *x, float *y, t_fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
}

void	shift_xy(t_fdf *data, int key)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
}

void	rotate(t_fdf *data, int key)
{
	if (key == 43)
	{
		data->scale += 0.1;
	}
	else
	{
		data->scale -= 0.1;
	}
}

void	zoom(t_fdf *data, int key)
{
	if (key == 41)
	{
		data->zoom += 1;
	}
	if (key == 39)
	{
		if (data->zoom == 1)
			data->zoom = 1;
		else
			data->zoom -= 1;
	}
}

void	change_z(t_fdf *data, int key)
{
	int	i;
	int	j;
	int	change;

	if (key == 24)
		change = 10;
	else
		change = -10;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			data->z_matrix[i][j] += change;
			j++;
		}
		i++;
	}
}
