/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:28:45 by cmartino          #+#    #+#             */
/*   Updated: 2022/11/16 16:15:17 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_free_join(char *stash, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(stash, buffer);
	free(buffer);
	return (tmp);
}

char	*ft_update_stash(char *stash)
{
	int		i;
	int		len;
	char	*buffer;

	i = 0;
	if (!stash)
		return (NULL);
	len = ft_strlen(stash);
	while (stash[i] != '\n' && stash[i])
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	buffer = ft_calloc(len - i + 1, 1);
	i++;
	len = 0;
	while (stash[i])
	{
		buffer[len] = stash[i];
		i++;
		len++;
	}
	free(stash);
	return (buffer);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[0])
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	line = ft_calloc(i + 2, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n' && stash[i])
	{
		line[i] = '\n';
		i++;
	}
	return (line);
}

char	*ft_readline(int fd, char *stash)
{
	char	*buffer;
	int		a;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
			return (NULL);
	if (!stash)
		stash = ft_calloc(1,1);
	a = 1;
	while (!ft_strrchr(buffer, '\n') && a > 0)
	{
		a = read(fd, buffer, BUFFER_SIZE);
		if (a < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[a] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX - 1)
		return (NULL);
	stash = ft_readline(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_update_stash(stash);
	return (line);
}

// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>

// int main(void)
// {
// 	int fd;
// 	int i;
// 	char *line;

// 	fd = open("text", O_RDONLY);
// 	i = 0;
// 	while (i < 2)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	// printf("[%s]\n\n", get_next_line(fd));
// 	// printf("[%s]\n\n", get_next_line(fd));
// 	// printf("[%s]\n\n", get_next_line(fd));
// 	// printf("[%s]\n\n", get_next_line(fd));
// 	// printf("[%s]\n\n", get_next_line(fd));
// 	// printf("[%s]\n\n", get_next_line(fd));
// 	// printf("[%s]\n\n", get_next_line(fd));
// 	close(fd);
// 	system("leaks a.out");
// 	return (0);
// }
