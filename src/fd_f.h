#ifndef FD_F_H
# define FD_F_H
# include "../mlx/mlx.h"
# include "../helpers/helpers.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		**color_matrix;
	int		zoom;
	int		color;
	int		x;
	int		y;
	int		shift_x;
	int		shift_y;
	int		win_width;
	int		win_length;
	t_data	mlx;

	void	*mlx_ptr;
	void	*win_ptr;
	float	scale;
}	t_fdf;

int		ft_atoi_base(const char *str, int str_base);
void	read_file(char *file_name, t_fdf *data);
void	bresenham_draw(float x, float y, float x1, float y1, t_fdf *data);
void	draw_map(t_fdf *data);
float	max(float first, float second);
float	module(float num);
void	isometric(float *x, float *y, int z, t_fdf *data);
void	change_z(t_fdf *data, int change);
void	shift_xy(t_fdf *data, int key);
void	rotate(t_fdf *data, int key);
void	zoom(t_fdf *data, int key);
int		get_length(char **splitted_line);
int		get_height(char *file_name);
void	free_split(char **splitted_arr);
int		get_width(char *file_name);
int		get_length(char **splitted_line);
#endif