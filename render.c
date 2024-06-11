#include "fractol.h"

void handle_pixel(int x, int y, t_fractal *fractal)
{
     t_complex z;
     t_complex c;

     z.x = 0.0;
     z.y = 0.0;
     c.x = scale(x, -2, 2);
     c.y = scale(x, 2, -2);
    while()
    {
        z = somme(square(z), c);
        if((z.x * z.x) + (z.y * z.y) > fractal->escape_v)
        {
            pixel_put();
            return ;
        }

    }
}

void fractal_render(t_fractal *fractal)
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
}