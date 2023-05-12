/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:41:43 by jungyeok          #+#    #+#             */
/*   Updated: 2023/05/04 18:09:48 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	free_split(char ***ret, int i)
{
	if (!(*ret)[i] && !(*ret)[i - 1][0])
	{
		free((*ret)[i - 1]);
		(*ret)[i - 1] = NULL;
	}
}

int	ft_atoi(char *s)
{
	int	si;
	int	a;
	int	i;

	if (!s)
		return (0);
	i = 0;
	si = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			si *= -1;
		i++;
	}
	a = 0;
	while ('0' <= s[i] && s[i] <= '9')
	{
		a *= 10;
		a += s[i] - '0';
		i++;
	}
	return (si * a);
}

float	ft_atof(char *s)
{
	int		i[3];
	float	f[2];

	i[SIGN] = 1;
	if (s[0] == '-')
		i[SIGN] = -1;
	i[INDEX] = -1 + 1 * (i[SIGN] == -1);
	f[ABS] = 0;
	i[DOT] = 0;
	f[FRAC] = 1;
	while (s[++i[INDEX]] != '\0')
	{
		if (i[DOT] && '0' <= s[i[INDEX]] && s[i[INDEX]] <= '9')
		{
			f[FRAC] /= 10;
			f[ABS] += (s[i[INDEX]] - '0') * f[FRAC];
		}
		else if (!i[DOT] && '0' <= s[i[INDEX]] && s[i[INDEX]] <= '9')
			f[ABS] = f[ABS] * 10 + s[i[INDEX]] - '0';
		else if (s[i[INDEX]] == '.')
			i[DOT] = 1;
		else
			break ;
	}
	return (i[SIGN] * f[ABS]);
}

bool	is_atoz(char *s)
{
	int	i;

	if (!s)
		return (false);
	i = 0;
	while (s[i])
	{
		if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))
			return (true);
		i++;
	}
	return (false);
}

int	ft_color(char *s)
{
	int		i[3];
	char	*tmp;

	tmp = s;
	i[RED] = ft_atoi(tmp);
	if (i[RED] < 0 || i[RED] > 255)
		err_msg("Invalid Red Color");
	tmp = ft_strchr(tmp, (int) ',');
	tmp++;
	i[GRE] = ft_atoi(tmp);
	if (i[GRE] < 0 || i[GRE] > 255)
		err_msg("Invalid Green Color");
	tmp = ft_strchr(tmp, (int) ',');
	tmp++;
	i[BLU] = ft_atoi(tmp);
	if (i[BLU] < 0 || i[BLU] > 255)
		err_msg("Invalid Blue Color");
	return (i[RED] * 65536 + i[GRE] * 256 + i[BLU]);
}
