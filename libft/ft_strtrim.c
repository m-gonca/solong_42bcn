/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:37:12 by mogonzal          #+#    #+#             */
/*   Updated: 2022/09/05 18:21:43 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)

{
	char	*ptr1;
	char	*result;
	size_t	start;
	size_t	end;
	size_t	count;

	ptr1 = (char *)s1;
	count = 0;
	while (ptr1[count] != '\0' && ft_strchr(set, ptr1[count]))
		count++;
	start = count;
	count = ft_strlen(ptr1);
	while (count > 0 && ft_strchr(set, ptr1[count]))
		count--;
	end = count;
	result = ft_substr(s1, start, end - start + 1);
	return (result);
}
