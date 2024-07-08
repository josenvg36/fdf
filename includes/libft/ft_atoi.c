/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:40:13 by jnajul            #+#    #+#             */
/*   Updated: 2024/03/10 15:40:52 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	count;

	i = 0;
	count = 0;
	sign = 1;
	if (nptr[i] == '\0')
		return (0);
	while (nptr[i] == 32 || (7 <= nptr[i] && nptr[i] <= 13))
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			sign = sign * (-1);
		i++;
	}
	while (48 <= nptr[i] && nptr[i] <= 57)
	{
		count = (count * 10) + (nptr[i] - 48);
		i++;
	}
	return ((int)sign * (int)count);
}

// #include <stdlib.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_atoi("      -785462"));
// 	printf("%d\n", atoi("      -785462"));
// 	return (0);
// }