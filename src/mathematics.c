#include <math.h>
#include "fd_f.h"

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
