#include "fd_f.h"

void	add_zoom(float *x, float *y, t_fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
}

void	add_shift(float *x, float *y, t_fdf *data)
{
	*x += data->shift_x;
	*y += data->shift_y;
}

void	color_choose(int z, int z1, t_fdf *data)
{
	if (z > 0 || z1 > 0)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	x += data->win_width / 2;
	y += data->win_length / 2;
	if ((x >= 0 && y >= 0) && \
			(x < data->win_width && y < data->win_length))
	{
		dst = data->mlx.addr + (y * data->mlx.line_length+ x * \
				(data->mlx.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}




void	bresenham_draw(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	add_zoom(&x, &y, data);
	add_zoom(&x1, &y1, data);
	z = (z * data->zoom) / 10;
	z1 = (z1 * data->zoom) / 10;
	color_choose(z, z1, data);
	isometric(&x, &y, z, data);
	isometric(&x1, &y1, z1, data);
	add_shift(&x, &y, data);
	add_shift(&x1, &y1, data);
	x_step = (x1 - x) / max(module(x1 - x), module(y1 - y));
	y_step = (y1 - y) / max(module(x1 - x), module(y1 - y));
	while ((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(data, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw_map(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham_draw(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham_draw(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
