/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:02:32 by jnajul            #+#    #+#             */
/*   Updated: 2024/03/08 14:54:16 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *des, const char *src, size_t size)
{
	size_t	i;
	size_t	rest;

	i = 0;
	while (des[i] && i < size)
		i++;
	rest = ft_strlcpy(des + i, src, size - i);
	return (rest + i);
}

	// rest = size - i - 1;
	// k = 0;
	// while (src[k] != '\0' && k < rest)
	// {
	// 	des[i + k] = src[k];
	// 	k++;
	// }
	// des[i + k] = '\0';