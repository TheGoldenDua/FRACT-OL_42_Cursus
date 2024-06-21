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
    // double old_max;
    // double old_range;
    // double new_range;
    // double old_position;
    // double result;

    old_min = 0;
    // old_max = 799;
    // old_range = old_max - old_min;
    // new_range = new_max - new_min;
    // old_position = (unscaled_num - old_min) / old_range;
    // result = new_min + old_position * new_range;
    return ((new_max - new_min)* (unscaled_num - old_min) / (old_max - old_min) + new_min );
}


int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (i < n - 1 && str1[i] && str2[i] && str1[i] == str2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}