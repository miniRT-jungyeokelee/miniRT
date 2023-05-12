/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 03:18:49 by jungyeok          #+#    #+#             */
/*   Updated: 2023/05/02 20:26:00 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	ft_memset(void *b, int c, int len)
{
	int				i;
	unsigned char	*d;

	d = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		d[i] = (unsigned char) c;
		i++;
	}
}

void	buf_ini(char buf[BUFFER_SIZE + 1])
{
	int	i;

	i = -1;
	while (++i <= BUFFER_SIZE)
		buf[i] = '\0';
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

void	*ft_calloc(int i, int j)
{
	int		n;
	int		ii;
	char	*ret;

	n = i * j;
	if (!n)
		return (NULL);
	ret = malloc(n);
	if (!ret)
		err_msg("Memory Allocation Error");
	ii = -1;
	while (++ii < n)
		ret[ii] = '\0';
	return ((void *)ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ret;

	ret = ft_calloc(1, ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	while (s1 && s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	return (ret);
}
