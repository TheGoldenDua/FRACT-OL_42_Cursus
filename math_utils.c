#include "fractol.h"

t_complex somme(t_complex z, t_complex c)
{
    t_complex result;

    result.x = z.x + c.x;
    result.y = z.y + c.y;
    return (result);
}


t_complex square(t_complex z)
{
    t_complex result;
    result.x = z.x * z.x - z.y * z.y;
    result.y = 2 * z.x * z.y;
    return (result);
}

double scale(double unscaled_num, double new_min, double new_max,double old_max)
{
    double old_min;

    old_min = 0;
    return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min );
}

