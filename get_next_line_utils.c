/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 13:53:51 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/31 11:20:39 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

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
	return (0);
}

t_list			*ft_list(t_list *lst, int fd)
{
	t_list	*beg_lst;
	t_list	*new;
	char	buffer[BUFFER_SIZE + 1];

	beg_lst = lst;
	while (beg_lst != NULL || beg_lst->fd != fd)
		beg_lst = beg_lst->next;
	if (beg_lst == NULL)
	{
		if (!(new = malloc(sizeof(t_list))))
			return (NULL);
		new->fd = fd;
		new->next = NULL;
		new->buffer = buffer;
		beg_lst = lst;
		while (beg_lst->next != NULL)
			beg_lst = beg_lst->next;
		beg_lst->next = new;
		return (new);
	}
	return (beg_lst);
}

static size_t	ft_strlchr(const char *s)
{
	size_t	i;

	i = 0;
	while (s[++i - 1] != '\0')
		if (s[i - 1] == '\n')
			return (i - 1);
	return (i - 1);
}

int				*ft_strjoin(char const *s1, char const *s2, t_list *lst_fd)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!(ptr = malloc(ft_strlchr(s1) + ft_strlchr(s2) + 1))
	|| s1 == NULL || s2 == NULL)
		return (-1);
	*ptr = 0;
	i = 0;
	j = 0;
	while (s1[++i - 1])
		ptr[i - 1] = s1[i - 1];
	free(s1);
	s1 = ptr;
	while (s2[j] && s2[j] != '\n')
	{
		ptr[i - 1 + j] = s2[j];
		j++;
	}
	ptr[i - 1 + j] = 0;
	if (s2[j] != '\n')
		return (1);
	ft_strdel(lst_fd);
	return (0);
}
