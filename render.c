/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:03:01 by del-ganb          #+#    #+#             */
/*   Updated: 2024/06/23 14:59:27 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pxl / 8));
	*(unsigned int *)(img->pxls_ptr + offset) = color;
}

static void	wich_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "Julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else if (!ft_strncmp(fractal->name, "BURNING_SHIP", 12))
	{
		c->x = z->x;
		c->y = z->y;
		z->x = fabs(z->x);
		z->y = fabs(z->y);
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = -1;
	z.x = (scale(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (scale(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	wich_fractal(&z, &c, fractal);
	while (++i < fractal->itr_def)
	{
		if (!ft_strncmp(fractal->name, "BURNING_SHIP", 12))
		{
			z.x = fabs(z.x);
			z.y = fabs(z.y);
		}
		z = somme(square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = scale(i, BLACK, WHITE, fractal->itr_def);
			pixel_put(x, y, &fractal->img, color);
			return ;
		}
	}
	pixel_put(x, y, &fractal->img, BLACK);
}

void	render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
			fractal->img.img_ptr, 0, 0);
}
