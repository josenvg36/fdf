/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:45:05 by jnajul            #+#    #+#             */
/*   Updated: 2024/03/07 15:59:42 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*ptr;

	start = 0;
	end = ft_strlen(s1);
	while (start < end && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	if (start == end)
		return (ft_strdup(""));
	len = end - start + 1;
	ptr = (char *)malloc(sizeof(char) * len);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1 + start, len - 1);
	ptr[len - 1] = '\0';
	return (ptr);
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = "  ..Jose..   ";
// 	s2 = " .";
// 	printf("%s", ft_strtrim(s1, s2));
// 	return (0);
// }
