/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:57:39 by jnajul            #+#    #+#             */
/*   Updated: 2024/03/10 18:16:30 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*ptr;
	size_t				i;

	ptr = (unsigned const char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == ((unsigned char)c))
			return ((unsigned char *)&ptr[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf ("%p\n", ft_memchr("Hello World", 'l', 3));
// 	printf ("%p\n", memchr("Hello World", 'l', 3));
// 	return (0);
// }