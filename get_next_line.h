/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:47:51 by htrindad          #+#    #+#             */
/*   Updated: 2024/06/11 13:27:13 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char const *str);
char	*ft_find_nl(char const *str);
char	*ft_strdup(char const *str);
char	*ft_strjoin(char *dest, char const *src);
char	*ft_substr(char const *str, size_t begin, size_t end);
char	*get_next_line(int fd);

#endif
