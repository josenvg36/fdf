/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:12:52 by jnajul            #+#    #+#             */
/*   Updated: 2024/07/08 16:45:42 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_first_line(char *line, t_data *data)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	data->width = 0;
	while (tokens[data->width])
		data->width++;
	free_tokens(tokens);
}

int	check_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	process_token(char *token, int *elevation, int *color)
{
	char	*comma;

	comma = ft_strchr(token, ',');
	if (comma)
	{
		*comma = '\0';
		*elevation = ft_atoi(token);
		*color = strtol(comma + 1, NULL, 16);
	}
	else
	{
		*elevation = ft_atoi(token);
		*color = 0x00FF00;
	}
}
