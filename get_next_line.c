/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 14:58:07 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/31 11:21:12 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_read_buffer(int fd, t_list *lst_fd)
{
	int		ret;

	ret = read(fd, lst_fd->buffer, BUFFER_SIZE);
	lst_fd->buffer[ret] = '\0';
	while (++ret < BUFFER_SIZE)
		lst_fd->buffer[ret] = '\0';
	return (ret);
}

static int		ft_clear_one_line(t_list *lst_fd, char **line, int fd)
{
	size_t	i;
	int		sign;

	i = 0;
	while (ft_strjoin(*line, lst_fd->buffer, lst_fd) == 1)
		if (ft_read_buffer(fd, lst_fd) == 0)
			return (0);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static t_list	*lst;
	t_list			*lst_fd;

	if (read(fd, 0, 0) == -1)
		return (-1);
	if (lst_fd = ft_list(lst, fd) == -1)
		return (-1);
	if (lst_fd->buffer == NULL)
		if (ft_read(fd, lst_fd) == 0)
			return (0);
	if (ft_clear_one_line(lst_fd, line, fd) == 1)
		return (-1);
	return (1);
}
