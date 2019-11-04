/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 13:53:51 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 14:34:14 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlchr(const char *s)
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

static void		ft_strdel(t_list *lst_fd)
{
	size_t i;
	size_t j;

	j = 0;
	i = ft_strlchr(lst_fd->buffer);
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

static char		*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int				ft_strjoin(t_list *lst_fd)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	// printf("STRJOIN start INFO\n");
	// printf("buffer = %s\n", lst_fd->buffer);
	// printf("line = %s\n", lst_fd->line);
	// printf("--------\n\n");	
	i = ft_strlchr(lst_fd->line);
	j = ft_strlchr(lst_fd->buffer);
	if (!(ptr = malloc(i + j + 1))
	|| lst_fd->buffer == NULL)
		return (-1);
	*ptr = 0;
	if (lst_fd->line != NULL)
		ptr = ft_strcat(ptr, lst_fd->line);
	free((void *)lst_fd->line);
	lst_fd->line = ptr;
	ptr = ft_strcat(ptr, lst_fd->buffer);
	ptr[i + j] = 0;
	if (lst_fd->buffer[j] != '\n')
		return (0);
	ft_strdel(lst_fd);
	// printf("STRJOIN END INFO\n");
	// printf("buffer = %s\n", lst_fd->buffer);
	// printf("line = %s\n", lst_fd->line);
	// printf("--------\n\n");
	return (1);
}
