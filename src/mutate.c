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
