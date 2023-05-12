/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 03:13:59 by jungyeok          #+#    #+#             */
/*   Updated: 2023/05/02 03:17:24 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	_end(t_mini *c)
{
	mlx_destroy_window(c->ptr, c->win);
	exit(0);
}

int	_key(int key, t_mini *c)
{
	if (key == KEY_ESC)
	{
		(void) c;
		exit(0);
	}
	return (0);
}
