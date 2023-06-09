/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:40:21 by jungyeok          #+#    #+#             */
/*   Updated: 2023/05/05 17:38:34 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	translate(float _this[3], float to_this[3])
{
	int	i;

	i = -1;
	while (++i < 3)
		_this[i] += to_this[i];
}
