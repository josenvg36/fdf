/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:05:07 by jnajul            #+#    #+#             */
/*   Updated: 2024/07/08 16:48:57 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_lines_and_width(const char *filename, t_data *data)
{
	int		fd;
	char	*line;
	int		line_count;

	fd = check_file(filename);
	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line_count == 0)
		{
			parse_first_line(line, data);
		}
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	data->height = line_count;
	close(fd);
}

void	allocate_arrays(t_data *data)
{
	data->elevations = allocate_2d_array(data->width, data->height);
	data->colors = allocate_2d_array(data->width, data->height);
	if (!data->elevations || !data->colors)
	{
		free_data(data);
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}
}

void	fill_elevations_and_colors(const char *filename, t_data *data)
{
	int		fd;
	int		row;
	int		col;
	char	**tokens;
	char	*line;

	fd = check_file(filename);
	row = 0;
	line = get_next_line(fd);
	while (line)
	{
		tokens = ft_split(line, ' ');
		col = 0;
		while (col < data->width)
		{
			process_token(tokens[col], &data->elevations[row][col], \
				&data->colors[row][col]);
			col++;
		}
		free_tokens(tokens);
		free(line);
		row++;
		line = get_next_line(fd);
	}
	close(fd);
}

void	parse_map_file(const char *filename, t_data *data)
{
	count_lines_and_width(filename, data);
	allocate_arrays(data);
	fill_elevations_and_colors(filename, data);
}
