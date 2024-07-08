/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:16:44 by jnajul            #+#    #+#             */
/*   Updated: 2024/03/07 19:20:49 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	int		i;

	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	i = 0;
	while (n > 0)
	{
		if (ptr1[i] != ptr2[i])
		{
			return ((unsigned char)ptr1[i] - (unsigned char)ptr2[i]);
		}
		i++;
		n--;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_memcmp("HE", "HG", 12));
// 	printf("%d\n", memcmp("HE", "HG", 12));
// 	return (0);
// }