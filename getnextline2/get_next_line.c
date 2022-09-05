/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:57:40 by mogonzal          #+#    #+#             */
/*   Updated: 2022/09/05 18:19:54 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *stock)
{
	char	*line;
	int		i;

	i = 0;
	if (!stock[i])
		return (NULL);
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	line = ft_substr(stock, 0, i + 1);
	return (line);
}

char	*ft_cut_line(char *stock)
{
	size_t	len;
	size_t	i;
	char	*new_stock;

	i = 0;
	if (stock[0] == '\0')
		return (NULL);
	len = ft_strlen(stock);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	new_stock = ft_substr(stock, i + 1, len);
	free(stock);
	return (new_stock);
}

char	*ft_fill(int fd, char *stock)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (read_bytes != 0 && ft_strchr(buffer, '\n') == NULL)
	{
		read_bytes = read (fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (buffer);
			return (NULL);
		}
		if (read_bytes > 0)
		{
			buffer[read_bytes] = '\0';
			stock = ft_strjoin(stock, buffer);
		}
	}
	free (buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*stock = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = ft_fill(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_get_line(stock);
	if (!line)
	{
		free(stock);
		return (NULL);
	}
	stock = ft_cut_line(stock);
	return (line);
}
