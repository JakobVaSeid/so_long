/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:42:52 by jseidere          #+#    #+#             */
/*   Updated: 2023/12/13 19:23:35 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*return_function(int index, char **stash)
{
	char		*result;
	size_t		len;

	if (!*stash)
		return (NULL);
	if (index <= 0)
	{
		if (**stash == 0 || index < 0)
		{
			free(*stash);
			*stash = NULL;
			return (NULL);
		}
		result = *stash;
		*stash = NULL;
		return (result);
	}
	len = ft_strlen(*stash) - index;
	result = *stash;
	*stash = ft_substr(*stash, index, len);
	result[index] = '\0';
	return (result);
}

char	*get_result(char **stash, char *buffer, int fd)
{
	char	*new_stash;
	char	*result;
	char	*next_line;
	ssize_t	bytesread;

	next_line = ft_strchr(*stash, '\n');
	while (next_line == NULL)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread <= 0)
			return (return_function(bytesread, stash));
		buffer[bytesread] = '\0';
		new_stash = ft_strjoin(*stash, buffer);
		free(*stash);
		*stash = new_stash;
		next_line = ft_strchr(*stash, '\n');
	}
	result = return_function(next_line - *stash + 1, stash);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(buffer));
	if (!buffer)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	result = get_result(&stash, buffer, fd);
	free(buffer);
	return (result);
}

/* int	main()
{
	char *str;
	str = get_next_line(0);
	free(str);
	return (0);
} */

/* int main()
{
	int i = 1;
	int fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Fehler beim Öffnen der Datei");
		return 1;
	}
	char *line;
	while (i <= 20)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("%d = %s\n", i, line);
			free(line);
		}
		else
		{
			break;
			printf("%d = Zeile nicht verfügbar\n", i);
		}
		printf("________________________\n");
	i++;
	}
	close(fd);
	return 0;
} */
/* #include <stdio.h>
int main()
{
	//int i = 1;
	int fd = open("newline.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Fehler beim Öffnen der Datei");
		return 1;
	}
	char *line;

	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
		// else
		// {
		// 	break;
		// 	printf("%d = Zeile nicht verfügbar\n", i);
		// }
		// printf("________________________\n");
		//i++;

	close(fd);
	return 0;
} */
