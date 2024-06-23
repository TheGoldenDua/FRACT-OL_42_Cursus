/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:03:33 by del-ganb          #+#    #+#             */
/*   Updated: 2024/06/23 14:03:34 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		fractal->zoom *= 1.08;
	}
	if (button == 4)
	{
		fractal->zoom /= 1.08;
	}
	render(fractal);
	return (0);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
		close_handler(fractal);
	else if (keycode == 65362)
		fractal->shift_y -= 0.3 * fractal->zoom;
	else if (keycode == 65364)
		fractal->shift_y += 0.3 * fractal->zoom;
	else if (keycode == 65363)
		fractal->shift_x -= 0.2 * fractal->zoom;
	else if (keycode == 65361)
		fractal->shift_x += 0.2 * fractal->zoom;
	else if (keycode == 61)
		fractal->itr_def += 10;
	else if (keycode == 45)
		fractal->itr_def -= 10;
	render(fractal);
	return (0);
}
