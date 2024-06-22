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

double ft_atod(char *str)
{
    double res;
	int signe;
    double j;

    res = 0;
	signe = 1;
	while(*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if(*str == '+' || *str == '-')
	{
		if(*str++ == '-')
			signe = -signe;
	}
	while(*str && *str >= '0' && *str <= '9')
        res = (res * 10) + (*str++ - '0');
	if(*str == '.')
		str++;
    j = 10;
	while(*str && *str >= '0' && *str <= '9')
    {
        res = res + (*str++ - '0') / j;
        j *= 10;
    }
	return (res * signe);
}