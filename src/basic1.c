/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 03:38:43 by jungyeok          #+#    #+#             */
/*   Updated: 2023/05/02 15:40:18 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s)
	{
		if (!c)
		{
			while (s[i])
				i++;
			return (s + i);
		}
		while (s[i])
		{
			if (s[i] == (char)c)
				return (s + i);
			i++;
		}
	}
	return (NULL);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_strlenc(char *s, char c)
{
	int	i;

	i = 0;
	if (s)
		while (s[i] && s[i] != c)
			i++;
	return (i);
}

char	*ft_strdupc(char *s, char c)
{
	int		i;
	int		len;
	char	*ret;

	if (!s)
		return (NULL);
	len = ft_strlenc(s, c);
	ret = ft_calloc(1, len + 1);
	i = 0;
	while (s[i] && s[i] != c)
	{
		ret[i] = s[i];
		i++;
	}
	return (ret);
}

char	**ft_split(char *s, char c)
{
	char	*cur;
	char	**ret;
	int		i[2];

	i[INDEX] = -1;
	i[NUMC] = 0;
	while (s[++i[INDEX]])
		if (s[i[INDEX]] == c)
			i[NUMC]++;
	ret = ft_calloc(8, i[NUMC] + 2);
	i[INDEX] = 0;
	cur = s;
	while (cur && i[INDEX] < i[NUMC] + 1)
	{
		ret[i[INDEX]] = ft_strdupc(cur, c);
		i[INDEX]++;
		cur = ft_strchr(cur, (int)c);
		while (cur && *cur == c)
			cur++;
	}
	while (i[NUMC] + 1 - i[INDEX])
		free(ret[i[NUMC]-- + 1]);
	free_split(&ret, i[NUMC] + 1);
	return (ret);
}
