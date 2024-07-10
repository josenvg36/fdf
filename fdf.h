/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:03:22 by jnajul            #+#    #+#             */
/*   Updated: 2024/07/08 17:19:02 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "includes/minilibx/mlx.h"
# include "includes/libft/get_next_line.h"
# include "includes/libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define ELEVATION_SCALE 5
# define ZOOM_FACTOR 1.05

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		offset_x;
	int		offset_y;
	double	zoom;
	int		**elevations;
	int		**colors;
	int		width;
	int		height;
	double	base_elevation;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_line
{
	t_point	p0;
	t_point	p1;
}	t_line;

typedef struct s_line_vars
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
}	t_line_vars;

typedef struct s_coords
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}	t_coords;

// Function prototypes
void	start_mlx_loop(t_data *data);
int		init_data(t_data *data);
void	parse_map_file(const char *filename, t_data *data);
void	fill_elevations_and_colors(const char *filename, t_data *data);
void	process_token(char *token, int *elevation, int *color);
void	allocate_arrays(t_data *data);
void	count_lines_and_width(const char *filename, t_data *data);
int		check_file(const char *filename);
void	parse_first_line(char *line, t_data *data);
void	free_tokens(char **tokens);
int		**allocate_2d_array(int width, int height);
void	free_data(t_data *data);
void	free_2d_array(int **array, int height);
void	draw_isometric_line(t_data *data, t_coords coords);
void	draw_isometric_grid(t_data *data);
t_point	to_isometric(t_data *data, int x, int y, int z);
void	draw_line(t_data *data, t_line *line, int color);
void	my_mlx_pp(t_data *data, int x, int y, int color);
int		mouse_scroll(int button, int x, int y, t_data *data);
int		key_press(int keycode, t_data *data);
int		close_window(t_data *data);

#endif
