/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:02:18 by jnajul            #+#    #+#             */
/*   Updated: 2024/03/08 13:19:54 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((ft_isalpha(c) || ft_isdigit(c)));
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%i\n", ft_isalnum('0'));
// 	printf("%i\n", isalnum('0'));
// 	return (0);
// }
