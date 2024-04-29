#ifndef FD_F_H
# define FD_F_H
# include "../minilibx_macos/mlx.h"
# include "../helpers/helpers.h"

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

void	read_file(char *file_name, t_fdf *data);
void	bresenham_draw(float x, float y, float x1, float y1, t_fdf *data);
void	draw_map(t_fdf *data);
float	max(float first, float second);
float	module(float num);
void	isometric(float *x, float *y, int z);
void	change_z(t_fdf *data, int change);
void	shift_xy(t_fdf *data, int key);
#endif