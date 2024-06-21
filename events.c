#include "fractol.h"

int close_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    exit(0);
}

int key_handler(int keycode, t_fractal *fractal)
{
    if(keycode == 65307)
        close_handler(fractal);
    else if(keycode == 65362)
        fractal->shift_y -= 0.3;
    else if(keycode == 65364)
        fractal->shift_y += 0.3;
    else if(keycode == 65363)
        fractal->shift_x -= 0.2;
    else if(keycode == 65361)
        fractal->shift_x += 0.2;
    else if(keycode == 65451)
        fractal->itr_def += 10;
    else if(keycode == 65453)
        fractal->itr_def -= 10;
    render(fractal);
    printf("%d\n", keycode);
    return 0;
}