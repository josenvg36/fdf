/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:36:17 by jnajul            #+#    #+#             */
/*   Updated: 2024/03/12 14:21:41 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_count(int num)
{
	int	count;

	count = 1;
	while (num > 9)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static char	*ft_fill(char *ptr, int n, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ptr[len - 1 - i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		num;
	size_t	len;
	char	*ptr;

	sign = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	num = n;
	len = ft_count(num) + sign;
	ptr = (char *)malloc((sizeof(char) * len) + 1);
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	ptr = ft_fill(ptr, n, len);
	if (sign == 1)
		ptr[0] = '-';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (ptr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(10));
// 	return (0);
// }