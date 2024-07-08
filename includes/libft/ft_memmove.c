/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:13:58 by jnajul            #+#    #+#             */
/*   Updated: 2024/03/07 19:36:36 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*castsrc;
	char	*castdes;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	castdes = (char *)dest;
	castsrc = (char *)src;
	if (castdes > castsrc)
		while (n-- > 0)
			castdes[n] = castsrc[n];
	else
	{
		i = 0;
		while (i < n)
		{
			castdes[i] = castsrc[i];
			i++;
		}
	}
	return ((void *)castdes);
}

// #include <stdio.h>
// #include <unistd.h>
// #include <string.h>

// int	main(void)
// {
// 	char	src[] = "lorem ipsum dolor sit amet";
// 	char	*dest;

// 	dest = src + 1;
// 	alarm (5);
// 	if (src != ft_memmove(src, dest, 8))
// 		write(1, "dest's adress was not returned\n", 31);
// 	write(1, dest, 22);
//     return (0);
// }