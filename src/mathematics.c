#include <math.h>

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

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}
