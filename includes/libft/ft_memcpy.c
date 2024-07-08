/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:07:44 by jnajul            #+#    #+#             */
/*   Updated: 2024/03/07 17:28:23 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*castdest;
	unsigned char	*castsrc;
	size_t			i;

	i = 0;
	castdest = (unsigned char *)dest;
	castsrc = (unsigned char *)src;
	while (i < n)
	{
		castdest[i] = castsrc[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	int	src[5] = {1, 2, 3, 4, 5};
// 	int	dest[3];

// 	printf("%p\n", ft_memcpy(dest, src, sizeof(int) * 3));
// 	printf("%p\n", ft_memcpy(dest, src, sizeof(int) * 3));
// 	return (0);
// }