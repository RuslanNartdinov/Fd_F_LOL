#ifndef FD_F_H
#define FD_F_H
#include "minilibx_macos/mlx.h"
#include "helpers/helpers.h"
typedef struct {
	int width;
	int height;
	int  **z_matrix;
	int zoom;
	int color;
	int shift_x;
	int shift_y;

	void *mlx_ptr;
	void *win_ptr;
}	fdf;

void read_file(char *file_name, fdf *data);
void bresenham_draw(float x, float y, float x1, float y1, fdf *data);
void draw_map(fdf *data);
#endif