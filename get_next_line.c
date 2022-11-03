/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:28:45 by cmartino          #+#    #+#             */
/*   Updated: 2022/11/03 08:38:14 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_readline(int fd, char *stash)
{
	int		a;
	int		i;
	int		test;
	char	*save;
	char	*buf;
	
	buf = malloc(sizeof(char) *  BUFFER_SIZE + 1);
	save = malloc(sizeof(char) *  BUFFER_SIZE + 1);
	if (!buf || !save)
		return (NULL);
	test = 1;
	while (test)
	{
		a = read(fd, buf, BUFFER_SIZE);
		if (a < 0)
			return (NULL);
		i = 0;
		while (buf[i] && buf[i] != '\n')
				i++;
		buf[i] = '\0';
		if (test == 0)
			ft_strlcpy(save, buf, BUFFER_SIZE + 1);
		else
			save = ft_strjoin(save, buf);
		if (a != BUFFER_SIZE || a != ft_strlen(buf))
			test = 0;
	}
	ft_strlcpy(stash, &buf[i + 1], BUFFER_SIZE);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_strdup(stash);
	buf = ft_readline(fd, stash);
	line = ft_strjoin(line, buf);
	return (line);
}

// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>

// int main(void)
// {
// 	int fd;

// 	fd = open("text", O_RDONLY);
// 	printf("[%s]\n\n", get_next_line(fd));
// 	printf("[%s]\n\n", get_next_line(fd));
// 	printf("[%s]\n\n", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
