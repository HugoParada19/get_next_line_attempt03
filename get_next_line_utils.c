/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:50:12 by htrindad          #+#    #+#             */
/*   Updated: 2024/06/11 13:19:59 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// nl stands for "new line"
char	*ft_find_nl(char const *str)
{
	char	*ptr;

	if (str == NULL)
		return (NULL);
	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr == '\n')
			return (ptr);
		ptr++;
	}
	return (NULL);
}

char	*ft_strdup(char const *str)
{
	char	*ptr;
	size_t	i;

	if (str == NULL)
		return (NULL);
	ptr = malloc(ft_strlen(str) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_strjoin(char *dest, char const *src)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	ptr = malloc(ft_strlen(dest) + ft_strlen(src) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (dest[i])
	{
		ptr[i] = dest[i];
		i++;
	}
	while (src[j])
	{
		ptr[i + j] = src[j];
		j++;
	}
	ptr[i + j] = 0;
	free(dest);
	return (ptr);
}

char	*ft_substr(char const *str, size_t begin, size_t end)
{
	char	*ptr;
	size_t	i;

	if (!str || !end || begin >= ft_strlen(str))
		return (NULL);
	if (begin + end >= ft_strlen(str))
		end = ft_strlen(str) - begin;
	ptr = malloc(end + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < end)
	{
		ptr[i] = str[i + begin];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
