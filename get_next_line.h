/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 13:53:48 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 14:03:41 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <string.h>


typedef struct		s_list
{
	int				fd;
	char			*ret;
	char			**line;
	struct s_list	*next;
}					t_list;


int					get_next_line(int fd, char **line);


#endif