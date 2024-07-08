/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:26:45 by jnajul            #+#    #+#             */
/*   Updated: 2024/03/08 13:47:04 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *des, const char *src, size_t size)
{
	size_t	i;

	i = ft_strlen(src);
	if (size == 0)
		return (i);
	while (*src != '\0' && (size - 1) > 0)
	{
		*des = *src;
		des++;
		src++;
		size--;
	}
	*des = '\0';
	return (i);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	src[13] = "Hello, World!";
// 	char	des[13];
// 	char	*ptr;

// 	printf("%ls\n", ft_strlcpy(des, src, sizeof(src)));
// 	printf("%ls\n", )
// 	return(0);
// }