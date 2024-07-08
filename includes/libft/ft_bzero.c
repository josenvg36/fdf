/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:48:55 by jnajul            #+#    #+#             */
/*   Updated: 2024/03/14 16:37:10 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*(ptr++) = '\0';
		n--;
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	buffer[10];
// 	size_t	i;

// 	ft_bzero(buffer, sizeof(buffer));
// 	bzero(buffer, sizeof(buffer));
// 	while (i < sizeof(buffer))
// 	{
// 		printf("%c", buffer[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	return (0);
// }
