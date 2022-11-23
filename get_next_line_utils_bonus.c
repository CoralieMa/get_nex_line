/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:03:03 by cmartino          #+#    #+#             */
/*   Updated: 2022/11/17 13:57:55 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = malloc(size * count);
	if (!str)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strncpy(const char *src, int dstsize)
{
	int		i;
	int		len;
	char	*dst;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (NULL);
	dst = malloc(sizeof(char) * dstsize + 1);
	if (!dst)
		return (NULL);
	while (src[i] && (i < dstsize))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	free(s1);
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[size] = '\0';
	return (str);
}
