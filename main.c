/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:04:37 by jnajul            #+#    #+#             */
/*   Updated: 2024/07/08 17:13:56 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (1);
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, \
		WINDOW_HEIGHT, "Isometric Grid");
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (1);
	}
	data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (data->img == NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (1);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bpp, \
		&data->line_length, &data->endian);
	return (0);
}

void	start_mlx_loop(t_data *data)
{
	mlx_key_hook(data->win, key_press, data);
	mlx_mouse_hook(data->win, mouse_scroll, data);
	draw_isometric_grid(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (1);
	if (init_data(&data) != 0)
		return (1);
	data.offset_x = -100;
	data.offset_y = -250;
	data.zoom = 1.0;
	data.base_elevation = ELEVATION_SCALE;
	parse_map_file(argv[1], &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	start_mlx_loop(&data);
	free_data(&data);
	return (0);
}
