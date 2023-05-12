/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:43:40 by jungyeok          #+#    #+#             */
/*   Updated: 2023/05/04 20:13:34 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	save_num(char **mapi, t_mini *c)
{
	if (!ft_strncmp(mapi[0], "A", 2))
		c->naml++;
	else if (!ft_strncmp(mapi[0], "C", 2))
		c->ncam++;
	else if (!ft_strncmp(mapi[0], "L", 2))
		c->nlig++;
	else if (!ft_strncmp(mapi[0], "sp", 3))
		c->nsph++;
	else if (!ft_strncmp(mapi[0], "pl", 3))
		c->npln++;
	else if (!ft_strncmp(mapi[0], "cy", 3))
		c->ncyl++;
	else
		err_msg("Invalid Contents");
}

void	save_info(char **mapi, t_mini *c, int i[4])
{
	if (!ft_strncmp(mapi[0], "A", 2))
		ft_a(mapi + 1, c);
	else if (!ft_strncmp(mapi[0], "C", 2))
		ft_c(mapi + 1, c);
	else if (!ft_strncmp(mapi[0], "L", 2))
		ft_l(mapi + 1, c);
	else if (!ft_strncmp(mapi[0], "sp", 3))
		ft_sp(mapi + 1, c, i);
	else if (!ft_strncmp(mapi[0], "pl", 3))
		ft_pl(mapi + 1, c, i);
	else if (!ft_strncmp(mapi[0], "cy", 3))
		ft_cy(mapi + 1, c, i);
}

void	free_mapi(char ***mapi)
{
	int	i;

	i = -1;
	while ((*mapi)[++i])
		free((*mapi)[i]);
	free((*mapi));
}

void	get_info(t_mini *c)
{
	int		i[4];
	char	**mapi;

	ft_memset(i, 0, 16);
	i[INDEX] = -1;
	while (c->map[++i[INDEX]])
	{
		mapi = ft_split(c->map[i[INDEX]], ' ');
		save_num(mapi, c);
		free_mapi(&mapi);
	}
	if (c->naml != 1 || c->ncam != 1)
		err_msg("Invalid Contents");
	if (c->nlig != 1)
		err_msg("Invalid Contents");
	c->sph = ft_calloc(sizeof(t_sp), c->nsph);
	c->pln = ft_calloc(sizeof(t_pl), c->npln);
	c->cyl = ft_calloc(sizeof(t_cy), c->ncyl);
	i[INDEX] = -1;
	while (c->map[++i[INDEX]])
	{
		mapi = ft_split(c->map[i[INDEX]], ' ');
		save_info(mapi, c, i);
		free_mapi(&mapi);
	}
}
