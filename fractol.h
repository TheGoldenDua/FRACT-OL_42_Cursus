#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include <unistd.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800

typedef struct s_complex
{
    double x;
    double y;
}t_complex;

typedef struct s_img
{
    void    *img_ptr;
    char    *pxls_ptr;
    int bits_per_pxl;
    int endian;
    int line_len;   
}t_img;

typedef struct s_fractal
{
    char    *name;
    void    *mlx_connection;
    void    *mlx_window;
    t_img   img;
    double escape_v;
}t_fractal;


double scale(double unscaled_num, double new_min, double new_max);
t_complex square(t_complex z);
t_complex somme(t_complex z, t_complex c);
int	ft_strncmp(char *s1, char *s2, size_t n);
void    fractol_init(t_fractal *fractal);


#endif