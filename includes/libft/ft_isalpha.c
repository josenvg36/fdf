/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:45:34 by jnajul            #+#    #+#             */
/*   Updated: 2024/03/08 13:19:23 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((65 <= c && c <= 90) || (97 <= c && c <= 122));
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	printf("%i\n", ft_isalpha('l'));
// 	printf("%i\n", isalpha('l'));
// 	return (0);
// }