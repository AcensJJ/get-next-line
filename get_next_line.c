/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 14:58:07 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 17:00:59 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_read_buffer(int fd, t_list **lst_fd)
{
	int		ret;
	char	*buffer;

	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	if ((*lst_fd)->buffer != NULL)
		free((*lst_fd)->buffer);
	(*lst_fd)->buffer = ft_strdup(buffer);
	free(buffer);
	buffer = NULL;
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
		ptr = ft_strcat_line(ptr, lst_fd->line);
	free(lst_fd->line);
	lst_fd->line = ptr;
	ptr = ft_strcat_line(ptr, lst_fd->buffer);
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
		if (a == -1 || b == -1)
			return (-1);
	}
	if (a == 0 && b == 0)
		return (0);
	return (1);
}

static t_list	*ft_list(t_list **lst, int fd)
{
	t_list	*beg_lst;
	t_list	*tmp;
	t_list	*new;

	beg_lst = *lst;
	while (beg_lst != NULL)
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
	new->line = NULL;
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
	char			*ligne;
	int				clear_val;

	ligne = NULL;
	lst_fd = ft_list(&lst, fd);
	if (read(fd, 0, 0) < 0 || line == NULL || lst_fd == NULL)
		return (-1);
	lst_fd->line = ligne;
	if (lst_fd->buffer[0] == '\0' || lst_fd->buffer == NULL)
		if (ft_read_buffer(fd, &lst_fd) == 0)
		{
			ft_del_list(&lst, lst_fd);
			*line = ft_strdup("");
			return (0);
		}
	clear_val = ft_clear_one_line(lst_fd, fd);
	*line = ft_strdup(lst_fd->line);
	free(lst_fd->line);
	if (clear_val == 0)
		ft_del_list(&lst, lst_fd);
	if (*line == NULL)
		*line = ft_strdup("");
	return (clear_val);
}
