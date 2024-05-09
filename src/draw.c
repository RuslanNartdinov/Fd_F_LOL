#include "fd_f.h"

void	add_shift(float *x, float *y, t_fdf *data)
{
	*x += data->shift_x;
	*y += data->shift_y;
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	x += data->win_width / 2;
	y += data->win_length / 2;
	if ((x >= 0 && y >= 0) && \
			(x < data->win_width && y < data->win_length))
	{
		dst = data->mlx.addr + (y * data->mlx.line_length + x * \
				(data->mlx.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	bresenham_draw(t_cd *c, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		z;
	int		z1;

	z = data->z_matrix[(int)c->y][(int)c->x];
	z1 = data->z_matrix[(int)c->y1][(int)c->x1];
	data->color = data->color_matrix[(int)c->y][(int)c->x];
	add_zoom(&(c->x), &(c->y), data);
	add_zoom(&(c->x1), &(c->y1), data);
	z = (z * data->zoom) / 10;
	z1 = (z1 * data->zoom) / 10;
	isometric(&(c->x), &(c->y), z, data);
	isometric(&(c->x1), &(c->y1), z1, data);
	add_shift(&(c->x), &(c->y), data);
	add_shift(&(c->x1), &(c->y1), data);
	x_step = (c->x1 - c->x) / max(module(c->x1 - c->x), module(c->y1 - c->y));
	y_step = (c->y1 - c->y) / max(module(c->x1 - c->x), module(c->y1 - c->y));
	while ((int)(c->x - c->x1) || (int)(c->y - c->y1))
	{
		my_mlx_pixel_put(data, c->x, c->y, data->color);
		c->x += x_step;
		c->y += y_step;
	}
}

t_cd	structure_init(float x, float y, float x1, float y1)
{
	t_cd	cd;

	cd.x = x;
	cd.x1 = x1;
	cd.y = y;
	cd.y1 = y1;
	return (cd);
}

void	draw_map(t_fdf *data)
{
	t_cd	cd;
	int		x;
	int		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				cd = structure_init(x, y, x + 1, y);
				bresenham_draw(&cd, data);
			}
			if (y < data->height - 1)
			{
				cd = structure_init(x, y, x, y + 1);
				bresenham_draw(&cd, data);
			}
			x++;
		}
		y++;
	}
}
