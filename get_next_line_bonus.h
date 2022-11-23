/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:03:16 by cmartino          #+#    #+#             */
/*   Updated: 2022/11/17 13:43:39 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

char	*get_next_line(int fd);
int		ft_strrchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);

#endif
