#include "fractol.h"

int handle_shift(int keycode, t_fractal *fractal)
{
    if (keycode == 2)
        fractal->shift_y += 0.4;
    printf("%d\n", keycode);
}