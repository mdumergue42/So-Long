/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:51:43 by madumerg          #+#    #+#             */
/*   Updated: 2024/01/03 16:02:58 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*str;

	if (!s2)
		return (NULL);
	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	free(s1);
	str[i] = '\0';
	return (str);
}

void	*ft_calloc_gnl(size_t ct, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (size == 0 || ct == 0)
		return (malloc(1));
	if ((int)size < 0 && (int)ct < 0)
		return (NULL);
	if ((unsigned long long)(size * ct) > UINT_MAX)
		return (NULL);
	str = malloc(size * ct);
	if (!str)
		return (NULL);
	while (i < (ct * size))
	{
		*(unsigned char *)(str + i) = '\0';
		i++;
	}
	return (str);
}
