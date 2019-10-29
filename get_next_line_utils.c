/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 13:53:51 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 18:03:00 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/* ************************************************************************** */
// NEEDING : 
//		-> new list
//		-> check fd exist , if yes, return position, else create it and return 
//		   this one
//		-> ft_strdel = sup avant le \n , ecrit jusqua \0 puis ecrit que
//		   des \0 jusqua la fin
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlchr(const char *s)
{
	long		i;

	i = -1;
	while (s[++i] != '\0')
		if (s[i] == "\n")
			return (i);
	return (i);
}

int		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!(ptr = malloc(ft_strlchr(s1) + ft_strlchr(s2) + 1))
	|| s1 == NULL || s2 == NULL)
		return (-1);
	*ptr = 0;
	i = -1;
	j = 0;
	while (s1[++i])
		ptr[i] = s1[i];
	while (s2[j] && s2[j] != '\n')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = 0;
	if (s2[j] != '\n')
		return (1);
	return (0);
}
