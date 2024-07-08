/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:16:12 by jnajul            #+#    #+#             */
/*   Updated: 2024/07/08 17:01:01 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		free_data(data);
		exit(0);
	}
	else if (keycode == 65361)
		data->offset_x -= 10;
	else if (keycode == 65363)
		data->offset_x += 10;
	else if (keycode == 65362)
		data->offset_y -= 10;
	else if (keycode == 65364)
		data->offset_y += 10;
	mlx_clear_window(data->mlx, data->win);
	draw_isometric_grid(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->zoom *= ZOOM_FACTOR;
	else if (button == 5)
		data->zoom /= ZOOM_FACTOR;
	mlx_clear_window(data->mlx, data->win);
	draw_isometric_grid(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	close_window(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}
