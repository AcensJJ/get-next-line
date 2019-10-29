/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 14:58:07 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 17:42:34 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_read_buffer(int fd, t_list *lst)
{
	int		ret;
	char	*buffer;

	ret = read(fd, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	if (ret != BUFFER_SIZE)
		buffer[++ret] = '\0';
	return (ret);
}

int		ft_clear_one_line(t_list *lst, char **line, int fd)
{
	/* ****************************************************************** */
	/* 	clear la ligne et boucle tant que pas de \n ou EOF				  */
	/*																	  */
	/* 	strchr \n si pas realloc tant que pqs de EOF					  */
	/*		-> realloc = join de (strlen de line + strlen de buffer)	  */
	/*																	  */
	/*	IF realloc fail, return -1 et free line							  */
	/*																	  */
	/* 	IF EOF quit 													  */
	/* ****************************************************************** */
	
	unsigned int	i;
	int				sign;
	
	i = 0;
	while (ft_read_buffer(fd, lst) != 0 && sign == 1)
	{
		sign = ft_strjoin();
		if (ft_read_buffer(fd, lst) != 0)
			break ;
	}
	return (sign);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*lst;

	if (read(fd, 0, 0) == -1)
		return (-1);
	if (lst->ret == NULL)
		if (ft_read(fd, lst) == 0)
			return (0);
	if (ft_clear_one_line(lst, line, fd) == -1)
		return (-1);
	return (1);
}
