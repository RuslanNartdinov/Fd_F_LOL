#include <math.h>
#include "fd_f.h"

void	initial_zoom(t_fdf *data)
{
	if (data->height > 355 || data->width > 800)
		data->zoom = 1;
	else if (data->height > 280 || data->width > 600)
		data->zoom = 2;
	else if (data->height > 175 || data->width > 400)
		data->zoom = 3;
	else if (data->height > 105 || data->width > 200)
		data->zoom = 4;
	else if (data->height > 70 || data->width > 100)
		data->zoom = 5;
	else if (data->height > 35 || data->width > 50)
		data->zoom = 10;
}

float	max(float first, float second)
{
	if (first >= second)
		return (first);
	else
		return (second);
}

float	module(float num)
{
	if (num > 0)
		return (num);
	else
		return (num * -1);
}

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->scale);
	*y = (*x + *y) * sin(data->scale) - z;
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			res = res * str_base + *str - 48;
		else if (*str >= 'A' && *str <= 'F')
			res = res * str_base + *str - 55;
		else if (*str >= 'a' && *str <= 'f')
			res = res * str_base + *str - 87;
		else
		{
			break ;
		}
		str++;
	}
	return (sign * res);
}
