/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cossadon <cossadon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:50:26 by cossadon          #+#    #+#             */
/*   Updated: 2024/03/06 15:52:26 by cossadon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_lines(int fd, char *next_line)
{
	int		bytes_read;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	if (!next_line)
	{
		next_line = malloc(1);
		if (!next_line)
			return (NULL);
		next_line[0] = '\0';
	}
	while (!ft_strchr(next_line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(next_line), free(buf), NULL);
		buf[bytes_read] = '\0';
		next_line = ft_strjoin(next_line, buf);
	}
	free(buf);
	return (next_line);
}

char	*end_of_line(char *next_line)
{
	char	*line;
	int		i;

	i = 0;
	if (!next_line)
		return (NULL);
	while (next_line[i] && next_line[i] != '\n')
		i++;
	if (next_line[i] == '\n')
		line = ft_strndup(next_line, i + 1);
	else
		line = ft_strndup(next_line, i);
	return (line);
}

char	*free_memory(char *line)
{
	int		i;
	int		j;
	char	*del;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	j = ft_strlen(line);
	if (!line[i])
		return (free(line), NULL);
	del = ft_strndup((line + i + 1), (j - i));
	if (del)
		free(line);
	return (del);
}

char	*get_next_line(int fd)
{
	static char		*next_line;
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	next_line = read_lines(fd, next_line);
	if (!next_line || next_line[0] == 0)
	{
		free(next_line);
		next_line = NULL;
		return (NULL);
	}
	line = end_of_line(next_line);
	if (!line || line[0] == 0)
		return (free(line), free(next_line), NULL);
	next_line = free_memory(next_line);
	if (next_line && next_line[0] == 0)
	{
		free(next_line);
		next_line = NULL;
	}
	return (line);
}

// int main()
// {
// 	int	fd;
// 	char	*line;

// 	fd = open("../../map/map1.ber", O_RDONLY);
//    	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }