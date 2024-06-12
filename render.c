#include "fractol.h"

static void pixel_put(int x, int y, t_img *img, int color)
{
    int offset;
    offset = (y * img->line_len) + (x * (img->bits_per_pxl / 8));
    *(unsigned int *)(img->pxls_ptr + offset) = color;
}

void handle_pixel(int x, int y, t_fractal *fractal)
{
     t_complex z;
     t_complex c;
     int    i;
     int    color;

     i = 0;
     z.x = 0.0;
     z.y = 0.0;
     c.x = scale(x, -2, 2);
     c.y = scale(x, 2, -2);
    while(i < fractal->itr_def)
    {
        z = somme(square(z), c);
        if((z.x * z.x) + (z.y * z.y) > fractal->escape_v)
        {
            color = scale(i, BLACK, WHITE);//the range start from 0 to 42
            pixel_put(x, y, &fractal->img, color);
            return ;
        }
        ++i;
    }
    //the point is in the mandelbrot set
    pixel_put(x, y, &fractal->img, PURPLE);
}

void render(t_fractal *fractal)
{
     int x;
     int y;

     y = -1;
     while(++y < HEIGHT)
     {
        x = -1;
        while(++x < WIDTH)
        {
            handle_pixel(x, y, fractal);
        }
     }
     mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}