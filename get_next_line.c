/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 14:58:07 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 18:15:40 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_read_buffer(int fd, t_list **lst_fd)
{
	int		ret;
	char	buffer[BUFFER_SIZE + 1];

	ret = read(fd, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	while (++ret <= BUFFER_SIZE)
		buffer[ret] = '\0';
	(*lst_fd)->buffer = ft_strdup(buffer);
	return (ret);
}

static int		ft_strjoin_lst(t_list *lst_fd)
{
	char	*ptr;
	size_t	i;
	size_t	j;

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
	return (1);
}

static int		ft_clear_one_line(t_list *lst_fd, int fd)
{
	int a;
	int b;

	a = 0;
	b = 1;
	while (a == 0 && b != 0)
	{
		a = ft_strjoin_lst(lst_fd);
		if (a == 0)
			b = ft_read_buffer(fd, &lst_fd);
		if (a == -1)
			return (-1);
	}
	return (0);
}

static t_list	*ft_list(t_list **lst, int fd, t_list *new)
{
	t_list	*beg_lst;
	t_list	*tmp;
	char	*line;

	beg_lst = *lst;
	line = NULL;
	while (beg_lst != NULL && beg_lst->fd != fd)
	{
		tmp = beg_lst;
		if (beg_lst->fd == fd)
			return (beg_lst);
		beg_lst = beg_lst->next;
	}
	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	new->buffer = NULL;
	new->line = line;
	ft_read_buffer(fd, &new);
	if (*lst == NULL)
		*lst = new;
	else
		tmp->next = new;
	return (new);
}

int				get_next_line(int fd, char **line)
{
	static t_list	*lst;
	t_list			*lst_fd;
	t_list			*new;

	new = NULL;
	if (read(fd, 0, 0) < 0 || line == NULL)
		return (-1);
	lst_fd = ft_list(&lst, fd, new);
	if (lst_fd == NULL)
		return (-1);
	if (lst_fd->buffer[0] == '\0' || lst_fd->buffer == NULL)
		if (ft_read_buffer(fd, &lst_fd) == 0)
			return (0);
	if (ft_clear_one_line(lst_fd, fd) == -1)
		return (-1);
	return (1);
}
