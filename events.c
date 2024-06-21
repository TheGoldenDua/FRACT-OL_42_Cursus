#include "fractol.h"

int close_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
    exit(0);
}

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    if(fractal->zoom > 0.0001f)
    {
        if(button  == 5)
        {
            fractal->zoom *= 1.08f;
        }
        if (button == 4)
        {
            fractal->zoom /= 1.08f;
        }
    }
    render(fractal);
    return (0);
}

int key_handler(int keycode, t_fractal *fractal)
{
    if(keycode == 65307)
        close_handler(fractal);
    else if(keycode == 65362)
        fractal->shift_y -= 0.3 * fractal->zoom;
    else if(keycode == 65364)
        fractal->shift_y += 0.3 * fractal->zoom;
    else if(keycode == 65363)
        fractal->shift_x -= 0.2 * fractal->zoom;
    else if(keycode == 65361)
        fractal->shift_x += 0.2 * fractal->zoom;
    else if(keycode == 65451)
        fractal->itr_def += 10;
    else if(keycode == 65453)
        fractal->itr_def -= 10;
    render(fractal);
    return 0;
}