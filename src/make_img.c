/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:00:08 by jungyeok          #+#    #+#             */
/*   Updated: 2023/05/05 22:47:08 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* CAM is (0, 0, 0)
 * orientation vector of cam is (0, 0, -1)
 * center of screen is (0, 0, -dist_scr)
 *
 * win address starts at (0, 0)
 * */
int	shoot_ray(t_mini *c, int i, int j)
{

}

void	make_img(t_mini *c)
{
	int	pixel;
	int	i;
	int	j;

	i = -1;
	while (++i < SHEI)
	{
		j = -1;
		while (++j < SWID)
		{
			pixel = c->adr + (y * c->s_l + x * (c->bpp / 8));
			*pixel = shoot_ray(c, i, j);
		}
	}
}
