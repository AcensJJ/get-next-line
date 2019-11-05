/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 13:53:51 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 14:21:27 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strcpy(char *dest, const char *src)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char		*ft_strdup(const char *src)
{
	char		*dest;
	size_t		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (!(dest = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	*dest = 0;
	ft_strcpy(dest, src);
	return (dest);
}

size_t		ft_strlchr(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

void		ft_strdel(t_list *lst_fd)
{
	size_t i;
	size_t j;

	j = 0;
	i = ft_strlchr(lst_fd->buffer) + 1;
	while (lst_fd->buffer[i] != '\0')
	{
		lst_fd->buffer[j] = lst_fd->buffer[i];
		i++;
		j++;
	}
	while (lst_fd->buffer[j] != '\0')
	{
		lst_fd->buffer[j] = '\0';
		j++;
	}
}

char		*ft_strcat_line(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && src[j] != '\n')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
