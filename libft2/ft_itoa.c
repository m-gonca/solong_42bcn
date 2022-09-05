/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:34:33 by mogonzal          #+#    #+#             */
/*   Updated: 2022/09/05 18:20:34 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_size(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count = 11;
	else
	{
		if (n < 0)
		{
			count++;
			n = -n;
		}
		while (n > 9)
		{
			n = n / 10;
			count++;
		}
		count++;
	}
	return (count);
}

char	*ft_putnumber(int n, char *number, int size)
{
	if (n == -2147483648)
	{
		number[0] = '-';
		number[1] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		number[0] = '-';
		n = -n;
	}
	while (size > 0 && n > 9)
	{
		number[size - 1] = '0' + n % 10;
		n = n / 10;
		size--;
	}
	number[size - 1] = '0' + n;
	return (number);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		size;

	size = ft_find_size(n);
	number = (char *)ft_calloc((size + 1), sizeof(char));
	if (!number)
		return (NULL);
	return (ft_putnumber(n, number, size));
}
