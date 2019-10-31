/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 14:58:07 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/31 16:59:06 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_read_buffer(int fd, t_list *lst_fd)
{
	int		ret;

	ret = read(fd, lst_fd->buffer, BUFFER_SIZE);
	lst_fd->buffer[ret] = '\0';
	while (++ret <= BUFFER_SIZE)
		lst_fd->buffer[ret] = '\0';
	return (ret);
}

static int		ft_clear_one_line(t_list *lst_fd, char **line, int fd)
{
	size_t	i;

	i = 0;
	while (ft_strjoin(*line, lst_fd->buffer, lst_fd) == 1)
		if (ft_read_buffer(fd, lst_fd) == 0)
			return (0);
	return (0);
}

static t_list	*ft_list(t_list *lst, int fd)
{
	t_list	*beg_lst;
	t_list	*new;
	char	buffer[BUFFER_SIZE + 1];
	char	*line;

	beg_lst = lst;
	while (beg_lst != NULL && beg_lst->fd != fd)
		beg_lst = beg_lst->next;
	if (beg_lst == NULL)
	{
		if (!(new = malloc(sizeof(t_list))))
			return (NULL);
		new->fd = fd;
		new->next = NULL;
		new->buffer = buffer;
		new->line = line;
		ft_read_buffer(fd, new);
		if (lst == NULL)
			return (new);
		beg_lst->next = new;
		return (new);
	}
	return (beg_lst);
}

int				get_next_line(int fd, char **line)
{
	static t_list	*lst;
	t_list			*lst_fd;

	if (read(fd, 0, 0) < 0 || line == NULL)
		return (-1);
	lst_fd = ft_list(lst, fd);
	if (lst_fd == NULL)
		return (-1);
	if (!lst)
		lst = lst_fd;
	if (lst_fd->buffer[0] == '\0')
		if (ft_read_buffer(fd, lst_fd) == 0)
			return (0);
	ft_clear_one_line(lst_fd, line, fd);
	return (1);
}
