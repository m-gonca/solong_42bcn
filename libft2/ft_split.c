/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:27:21 by mogonzal          #+#    #+#             */
/*   Updated: 2022/09/05 18:21:16 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_count(char const *s, char c)
{
	int		words_count;
	int		y;

	y = 0;
	words_count = 0;
	while (s[y] != '\0')
	{
		if (s[y] == c)
			y++;
		else
		{
			words_count++;
			while (s[y] != c && s[y])
				y++;
		}		
	}
	return (words_count);
}

static char	**free_in_case_error(char **ptr)
{
	int	count;

	count = 0;
	while (ptr[count])
	{
		free(ptr[count]);
		count++;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		y;
	int		x;
	int		words_in_result;
	int		words_count;

	words_count = ft_words_count(s, c);
	ptr = (char **)ft_calloc ((words_count + 1), sizeof(char *));
	if (!ptr)
		return (NULL);
	y = 0;
	x = 0;
	words_in_result = 0;
	while (words_in_result < words_count)
	{
		while (s[y] && s[y] == c)
			x = ++y;
		while (s[y] && s[y] != c)
			y++;
		ptr[words_in_result] = ft_substr((const char *)s, x, y - x);
		if (ptr[words_in_result] == NULL)
			return (free_in_case_error(ptr));
		words_in_result++;
	}
	return (ptr);
}
