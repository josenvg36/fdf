/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:39:41 by jnajul            #+#    #+#             */
/*   Updated: 2024/07/08 16:30:38 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*set_line(char *line)
{
	int		i;
	char	*line_remain;

	i = 0;
	line_remain = NULL;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	line_remain = ft_substr_gnl(line, (i + 1), ft_strlen_gnl(line) + 1);
	if (line_remain[0] == '\0')
	{
		free (line_remain);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (line_remain);
}

char	*fill_buffer(int fd, char *last_char, char *buffer)
{
	int		buffer_len;
	char	*tmp;

	buffer_len = 1;
	while (buffer_len)
	{
		buffer_len = read(fd, buffer, BUFFER_SIZE);
		if (buffer_len == 0)
			break ;
		if (buffer_len == -1)
			return (NULL);
		buffer[buffer_len] = '\0';
		if (!last_char)
			last_char = ft_strdup_gnl("");
		tmp = last_char;
		last_char = ft_strjoin_gnl(tmp, buffer);
		free (tmp);
		tmp = NULL;
		if (!last_char)
			return (NULL);
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	return (last_char);
}

char	*get_next_line(int fd)
{
	static char	*last_char;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = fill_buffer(fd, last_char, buffer);
	free (buffer);
	if (line == NULL)
		return (NULL);
	buffer = NULL;
	last_char = set_line(line);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("text.txt",O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s\n", line);
// 		free (line);
// 	}
// 	free (line);
// 	line = NULL;
// 	printf("%d\n", fd);
// 	close (fd);
// 	return (0);
// }