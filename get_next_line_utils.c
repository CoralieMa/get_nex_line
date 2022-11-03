/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:28:53 by cmartino          #+#    #+#             */
/*   Updated: 2022/11/03 08:22:49 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while ((src[i] || src[i] == '\n') && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

char	*ft_strdup(const char *s1)
{
	int	len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = (char *) malloc(len * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, len + 1);
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	s1_len;
	int	s2_len;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s = (char *) malloc((s1_len + s2_len) * sizeof(char) + 1);
	if (!s)
		return (NULL);
	s[s1_len + s2_len] = '\0';
	ft_strlcpy(s, s1, s1_len + 1);
	ft_strlcpy(&s[s1_len], s2, s2_len + 1);
	return (s);
}

//  #include <stdio.h>

// int main(void)
// {
// 	printf("%s", ft_strdup("Hello"));
// }