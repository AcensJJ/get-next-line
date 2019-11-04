/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 14:58:07 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 16:03:10 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_read_buffer(int fd, t_list **lst_fd)
{
	int		ret;

	ret = read(fd, (*lst_fd)->buffer, BUFFER_SIZE);
	(*lst_fd)->buffer[ret] = '\0';
	while (++ret <= BUFFER_SIZE)
		(*lst_fd)->buffer[ret] = '\0';

	// printf("After READ BUFFER\n");
	// printf("buffer = %s\n\n", (*lst_fd)->buffer);

	return (ret);
}

static int		ft_clear_one_line(t_list *lst_fd, int fd)
{
	int a;
	int b;

	a = 1;
	b = 1;

	// printf("CLEAR start INFO\n");
	// printf("a = %d\n", a);
	// printf("b = %d\n", b);
	
	while (a == 1 && b != 0)
	{
		a = ft_strjoin(lst_fd);
		b = ft_read_buffer(fd, &lst_fd);

		// printf("After Clear ONE\n");
		// printf("buffer = %s\n\n", lst_fd->buffer);

		// printf("CLEAR END INFO\n");
		// printf("a = %d\n", a);
		// printf("b = %d\n", b);
		// printf("--------\n\n");

		// sleep(5);

		if (a == -1)
			return (-1);
	}
	return (0);
}

static t_list	*ft_list(t_list **lst, int fd)
{
	t_list	*beg_lst;
	t_list	*tmp;
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	t_list			*new = NULL;

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
	new->buffer = buffer;
	new->line = line;
	ft_read_buffer(fd, &new);

	printf("After LIST ADD\n");
	printf("1\n");
	printf("buffer = %s\n\n", new->buffer);
	printf("%p \n", new->buffer);

	if (*lst == NULL)
		*lst = new;
	else
		tmp->next = new;

	printf("2\n");
	printf("buffer = %s\n\n", new->buffer);


	return (new);
}

int				get_next_line(int fd, char **line)
{
	static t_list	*lst;
	t_list			*lst_fd;


	if (read(fd, 0, 0) < 0 || line == NULL)
		return (-1);
	ft_list(&lst, fd);
	if (lst_fd == NULL)
		return (-1);

	if (lst_fd)
	{
		printf("%p \n", lst_fd->buffer);
		printf("After LIST IN GNL\n");
		printf("3\n");
		printf("buffer = |%s|\n\n", lst_fd->buffer);
	}
	/*
	if (lst_fd->buffer[0] == '\0' || lst_fd->buffer == NULL)
		if (ft_read_buffer(fd, lst_fd) == 0)
			return (0);
	printf("After GNL\n");
	printf("buffer = %s\n\n", lst_fd->buffer);
	if (ft_clear_one_line(lst_fd, fd) == -1)
		return (-1);
	return (1);
	*/

	return (0);
}
