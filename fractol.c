/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:03:29 by del-ganb          #+#    #+#             */
/*   Updated: 2024/06/23 19:53:20 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_args(char **argv, t_fractal *fractal)
{
	if (!is_digit(argv[2]) || !is_digit(argv[3]))
	{
		fractal->julia_x = ft_atod(argv[2]);
		fractal->julia_y = ft_atod(argv[3]);
	}
	else
	{
		write(1, "the parameters has to be digits", 30);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && (!ft_strncmp(argv[1], "Mandelbrot", 10)
				|| !ft_strncmp(argv[1], "BURNING_SHIP", 12))) || (argc == 4
			&& !ft_strncmp(argv[1], "Julia", 5)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(argv[1], "Julia", 5))
		{
			check_args(argv, &fractal);
		}
		fractol_init(&fractal);
		render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		write(1, "Error, Incorrect Parameters!\n", 29);
		exit(1);
	}
}
