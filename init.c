#include "fractol.h"

static void error_malloc(void)
{
    perror("problems with malloc");
    exit(1);
}

void data_init(t_fractal *fractal)
{
    fractal->escape_v = 4; // 2^2
    fractal->itr_def = 42;
}

void    fractol_init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if(fractal->mlx_connection == NULL)
        error_malloc();//todo
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
    if(fractal->mlx_window == NULL)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        error_malloc();//TODO
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
    if(fractal->img.img_ptr == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        error_malloc();//TOD
    }
    fractal->img.pxls_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bits_per_pxl, &fractal->img.line_len, &fractal->img.endian);     
}