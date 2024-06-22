#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include <unistd.h>
#include <math.h>
#include <X11/X.h>

#define WIDTH 800
#define HEIGHT 800

#define BLACK   0x000000
#define WHITE   0xFFFFFF
#define RED     0xFF0000
#define GREEN   0x00FF00
#define BLUE    0x0000FF
#define YELLOW  0xFFFF00
#define CYAN    0x00FFFF
#define MAGENTA 0xFF00FF
#define GRAY    0x808080
#define ORANGE  0xFFA500
#define PINK    0xFFC0CB
#define BROWN   0xA52A2A
#define PURPLE  0x800080
#define LIME    0x00FF00
#define NAVY    0x000080
#define TEAL    0x008080
#define OLIVE   0x808000
#define MAROON  0x800000
#define SILVER  0xC0C0C0
#define GOLD    0xFFD700

#define COLOR1  0xdc0531

typedef struct s_complex
{
    double x;
    double y;
}t_complex;

typedef struct s_img
{
    void    *img_ptr;
    char    *pxls_ptr;
    int     bits_per_pxl;
    int     endian;
    int     line_len;   
}t_img;

typedef struct s_fractal
{
    char    *name;
    void    *mlx_connection;
    void    *mlx_window;
    t_img   img;
    double     itr_def;
    int     color;
    double     zoom;
    double     shift_x;
    double     shift_y;
    double     julia_x;
    double     julia_y;
}t_fractal;


double scale(double unscaled_num, double new_min, double new_max,double old_max);
t_complex square(t_complex z);
t_complex somme(t_complex z, t_complex c);
int	ft_strncmp(char *s1, char *s2, size_t n);
void    fractol_init(t_fractal *fractal);
void render(t_fractal *fractal);
void handle_pixel(int x, int y, t_fractal *fractal);
void data_init(t_fractal *fractal);
void    fractol_init(t_fractal *fractal);
int close_handler(t_fractal *fractal);
int mouse_handler(int button, int x, int y,t_fractal *fractal);
int key_handler(int keycode, t_fractal *fractal);
double ft_atod(char *str);


#endif