/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 02:39:11 by jungyeok          #+#    #+#             */
/*   Updated: 2023/05/05 22:38:13 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void	_print(t_mini *c){
	printf("\nnaml = %d, ncam = %d, nlig = %d\n", c->naml, c->ncam, c->nlig);
	printf("\nnsph = %d, npln = %d, ncyl = %d\n", c->nsph, c->npln, c->ncyl);
	
	for (int i = 0; i < c->nsph; i++){
		printf("\n ---- about sphere %d ---- \n", i);
		printf("center = (%f, %f, %f)\n", c->sph[i].center[X]
			, c->sph[i].center[Y], c->sph[i].center[Z]);
		printf("diameter = %f, color = %d\n"
			, c->sph[i].diameter, c->sph[i].color);
	}
	
	for (int i = 0; i < c->npln; i++){
		printf("\n ---- about plane %d ---- \n", i);
		printf("point in plane = (%f, %f, %f)\n", c->pln[i].point_pl[X]
			, c->pln[i].point_pl[Y], c->pln[i].point_pl[Z]);
		printf("normal vector in plane = (%f, %f, %f)\n", c->pln[i].n_vec[X]
			, c->pln[i].n_vec[Y], c->pln[i].n_vec[Z]);
		printf("color = %d\n", c->pln[i].color);
	}
	
	for (int i = 0; i < c->ncyl; i++){
		printf("\n ---- about cylinder %d ---- \n", i);
		printf("center in cylinder = (%f, %f, %f)\n", c->cyl[i].center[X]
			, c->cyl[i].center[Y], c->cyl[i].center[Z]);
		printf("axis in cylinder = (%f, %f, %f)\n", c->cyl[i].axis[X]
			, c->cyl[i].axis[Y], c->cyl[i].axis[Z]);
		printf("diameter = %f, height = %f\n"
			, c->cyl[i].diameter, c->cyl[i].height);
		printf("color = %d\n", c->cyl[i].color);
	}
	
	exit(0);
}

void	down_map(t_mini *c, char *s, int fd, int r)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	if (ft_strncmp(ft_strchr(s, 46), ".rt\0", 4))
		err_msg("Input File is NOT .rt type");
	fd = open(s, O_RDONLY);
	if (fd < 0)
		err_msg("Invalid Input File");
	c->l_map = ft_calloc(1, 1);
	while (r == BUFFER_SIZE)
	{
		buf_ini(buf);
		r = read(fd, buf, BUFFER_SIZE);
		tmp = c->l_map;
		c->l_map = ft_strjoin(tmp, buf);
		free(tmp);
	}
	close(fd);
	c->map = ft_split(c->l_map, '\n');
	free(c->l_map);
	get_info(c);
}

void	_sys(t_mini *c)
{
	c->ptr = mlx_init();
	c->win = mlx_new_window(c->ptr, SWID, SHEI, "miniRT");
	mlx_clear_window(c->ptr, c->win);
	c->img = mlx_new_image(c->ptr, SWID, SHEI);
	c->adr = mlx_get_data_addr(c->img, &c->bpp, &c->s_l, &c->end);
}

void	_hook(t_mini *c)
{
	mlx_key_hook(c->win, &_key, c);
	mlx_hook(c->win, RED_BUTTON, 0, &_end, c);
}

/* 11 dd
 * */
void  my_mlx_pixel_put(t_mini *c, int x, int y, int color)
{
  unsigned int *dst;

  dst = c->adr + (y * c->s_l + x * (c->bpp / 8));
  *dst = color;
}
/**/

void	_draw(t_mini *c)
{
	c->dist_scr = (SWID / tan(c->cam.fov / 2)) / 2;
	make_origin_to_cam(c);
	make_cam_orient_to_my_orient(c);
	make_img(c);
/* 9dd
 * */
	int k;
	k = 0;
	for (int i = 250, k = 99; i < 300; i++, k -= 2){
		for (int j = 150 + k; j < 250; j++)
      		my_mlx_pixel_put(c, i, j, 0x00FF00);
	}
/**/	
	mlx_put_image_to_window(c->ptr, c->win, c->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_mini	c;

	if (ac != 2)
		return (1);
	ft_memset(&c, 0, sizeof(c));
	down_map(&c, av[1], -1, BUFFER_SIZE);
//	_print(&c);
	_sys(&c);
	_draw(&c);
	_hook(&c);
	mlx_loop(c.ptr);
}
//system("leaks miniRT");
