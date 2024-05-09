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
