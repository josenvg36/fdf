/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:52:35 by jnajul            #+#    #+#             */
/*   Updated: 2024/03/12 14:22:41 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (words);
}

static void	ft_initialize(int *i, int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = 0;
}

static char	**ft_ptr(const char *s, char c)
{
	char	**ptr;

	ptr = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}

static int	ft_start_word(char const *s, char c, int i)
{
	while (s[i] == c && s[i])
		i++;
	return (i);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	ft_initialize(&i, &j, &k);
	ptr = ft_ptr(s, c);
	while (s[i])
	{
		i = ft_start_word(s, c, i);
		k = i;
		while (s[i] != c && s[i])
			i++;
		if (i > k)
		{
			ptr[j] = ft_substr(s, k, i - k);
			if (ptr[j] == NULL)
				return (NULL);
			j++;
		}
	}
	ptr[j] = NULL;
	return (ptr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	**arr;

// 	arr = ft_split("Hello World", ' ');
// 	printf("%s\n", arr[0]);
// 	printf("%s\n", arr[1]);
// 	return (0);
// }
