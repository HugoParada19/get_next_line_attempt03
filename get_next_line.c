/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:44:36 by htrindad          #+#    #+#             */
/*   Updated: 2024/06/11 13:38:18 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_buf(int fd, char *buf)
{
	char	temp[BUFFER_SIZE + 1];
	int		chars_r;
	size_t	i;

	i = 0;
	while (i <= BUFFER_SIZE)
		temp[i++] = 0;
	chars_r = 1;
	while (!ft_find_nl(buf) && chars_r)
	{
		chars_r = read(fd, temp, BUFFER_SIZE);
		if (chars_r < 0 || (!chars_r && !buf))
			return (NULL);
		temp[chars_r] = 0;
		if (buf == NULL)
			buf = ft_strdup(temp);
		else
			buf = ft_strjoin(buf, temp);
		if (buf == NULL)
			return (NULL);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*next_l = NULL;
	char		*pre_str;
	char		*post_str;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	next_l = get_buf(fd, next_l);
	if (next_l == NULL)
		return (NULL);
	i = 0;
	while (next_l[i] != '\n' && next_l[i])
		i++;
	i += (next_l[i] == '\n');
	pre_str = ft_substr(next_l, 0, i);
	post_str = ft_substr(next_l, i, ft_strlen(next_l) - i);
	free(next_l);
	next_l = post_str;
	return (pre_str);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	const int times = 4;
	char *str;

	fd = open("test.txt", O_RDONLY);
	for (int i = 0; i < times; i++)
	{
		printf("%s\n", str = get_next_line(fd));
		free(str);
	}
}


/* type the following on your command line
 *	echo "I’m hurt\nand I’m old\nand I’m fucking tired\nand I work with fucking children" > test.txt
*/
