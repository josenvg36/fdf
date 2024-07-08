/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:25:47 by jnajul            #+#    #+#             */
/*   Updated: 2024/03/05 14:00:45 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*char_dest;

	i = 0;
	char_dest = (unsigned char *)s;
	while (i < n)
	{
		char_dest[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	buffer[10];
// 	size_t	i;

// 	printf("%p\n", ft_memset(buffer, 'c', 5));
// 	printf("%p\n", memset(buffer, 'c', sizeof(buffer)));
// 	i = 0;
// 	while (i < sizeof(buffer))
// 	{
// 		printf("%c", buffer[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	return (0);
// }