/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:14:10 by jose              #+#    #+#             */
/*   Updated: 2024/07/08 14:16:17 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pp(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	init_line_vars(t_line_vars *vars, t_line *line)
{
	vars->dx = abs(line->p1.x - line->p0.x);
	if (line->p0.x < line->p1.x)
		vars->sx = 1;
	else
		vars->sx = -1;
	vars->dy = -abs(line->p1.y - line->p0.y);
	if (line->p0.y < line->p1.y)
		vars->sy = 1;
	else
		vars->sy = -1;
	vars->err = vars->dx + vars->dy;
}

void	draw_line(t_data *data, t_line *line, int color)
{
	t_line_vars	vars;
	int			e2;

	init_line_vars(&vars, line);
	e2 = 0;
	while (1)
	{
		my_mlx_pp(data, line->p0.x, line->p0.y, color);
		if (line->p0.x == line->p1.x && line->p0.y == line->p1.y)
			break ;
		e2 = 2 * vars.err;
		if (e2 >= vars.dy)
		{
			vars.err += vars.dy;
			line->p0.x += vars.sx;
		}
		if (e2 <= vars.dx)
		{
			vars.err += vars.dx;
			line->p0.y += vars.sy;
		}
	}
}

int	**allocate_2d_array(int width, int height)
{
	int	**array;
	int	i;
	int	j;

	array = (int **)malloc(sizeof(int *) * height);
	if (!array)
		return (NULL);
	i = 0;
	while (i < height)
	{
		array[i] = (int *)malloc(sizeof(int) * width);
		if (!array[i])
		{
			j = 0;
			while (j < i)
			{
				free(array[j]);
				j++;
			}
			free(array);
			return (NULL);
		}
		i++;
	}
	return (array);
}
