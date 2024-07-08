/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:26:33 by jnajul            #+#    #+#             */
/*   Updated: 2024/07/08 17:08:47 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	to_isometric(t_data *data, int x, int y, int z)
{
	t_point	iso;

	iso.x = (x - y) * cos(M_PI / 6) * data->zoom + WINDOW_WIDTH / 2 + \
		data->offset_x;
	iso.y = (x + y) * sin(M_PI / 6) * data->zoom - z + WINDOW_HEIGHT \
	/ 2 + data->offset_y;
	return (iso);
}

void	draw_isometric_line(t_data *data, t_coords coords)
{
	t_line	line;
	int		z1;
	int		z2;
	int		color;

	z1 = data->elevations[coords.y1][coords.x1] * \
	data->base_elevation * data->zoom;
	z2 = data->elevations[coords.y2][coords.x2] * \
	data->base_elevation * data->zoom;
	color = data->colors[coords.y1][coords.x1];
	line.p0 = to_isometric(data, coords.x1 * 40, coords.y1 * 40, z1);
	line.p1 = to_isometric(data, coords.x2 * 40, coords.y2 * 40, z2);
	draw_line(data, &line, color);
}

t_coords	init_coords(int x1, int y1, int x2, int y2)
{
	t_coords	coords;

	coords.x1 = x1;
	coords.y1 = y1;
	coords.x2 = x2;
	coords.y2 = y2;
	return (coords);
}

void	draw_isometric_grid(t_data *data)
{
	int			x;
	int			y;
	t_coords	coords;

	ft_memset(data->addr, 0, WINDOW_WIDTH * WINDOW_HEIGHT * (data->bpp / 8));
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				coords = init_coords(x, y, x + 1, y);
				draw_isometric_line(data, coords);
			}
			if (y < data->height - 1)
			{
				coords = init_coords(x, y, x, y + 1);
				draw_isometric_line(data, coords);
			}
			x++;
		}
		y++;
	}
}
