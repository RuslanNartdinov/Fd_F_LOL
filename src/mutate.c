#include "fd_f.h"

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
		if (data->scale == 1)
			data->scale = 0.1;
		else
			data->scale += 0.1;
	}
	else
	{
		if (data->scale == 0)
			data->scale = 1;
		else
			data->scale -= 0.1;
	}
}

void	zoom(t_fdf *data, int key)
{
	if (key == 41)
	{
		if (data->zoom >= 200)
			data->zoom = 200;
		else
			data->zoom += 5;
	}
	if (key == 39)
	{
		if (data->zoom <= 10)
			data->zoom = 10;
		else
			data->zoom -= 5;
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
