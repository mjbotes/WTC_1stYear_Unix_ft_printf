/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 08:33:43 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/12 10:06:48 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_hashtag(char **c, t_format *form)
{
	int 	loop;
	char	*str;
	int		num;

	loop = 0;
	while (ft_isdigit(*c[loop]))
			loop ++;
	if (loop != 0)
	{
		str = ft_strndup(*c, loop);
		num = ft_atoi(str);
		ft_strdel(&str);
		str = ft_strdup(*(c + loop));
		ft_strdel(c);
		*c = ft_strdup(str);
	}
}

void	ft_justify(char **c, t_format *form)
{
	int 	loop;
	char	*str;
	int		num;

	loop = 0;
	ft_putendl(c);
	if (*(c)[0] == '0')
	{
		loop = 1;
		form->pad_type = '0';
	}
	if (*(c)[loop] == '+' || *(c)[loop] == '-')
		loop++;
	while (ft_isdigit(*(c)[loop]))
			++loop;
	if (loop != 0)
	{
		str = ft_strsub(*c, 0, loop + 1);
		num = ft_atoi(str);
		if (num > 0)
			form->left_pad = num;
		if (num < 0 && loop++)
			form->right_pad = num;
		ft_strdel(&str);
		str = ft_strdup(*(c) + loop);
		ft_strdel(c);
		*c = ft_strdup(str);
	}
}

void	ft_space(char **c, t_format *form)
{
    int     loop;
    char    *str;
    int     num;

    loop = 1;
	if (*c[loop] == '-' || *c[loop] == '+')
		loop++;
	while (ft_isdigit(*(c)[loop]))
		loop ++;
	str = ft_strsub(*c, 1, loop + 1);
	num = ft_atoi(str);
	if (num == 0)
		num = 1;
	form->space = num;
	if (num < 0)
		loop++;
	ft_strdel(&str);
	str = ft_strdup(&(*(c)[loop]));
	ft_strdel(c);
	*c = ft_strdup(str);
}

void	ft_isintmax(t_format form)
{

}

void	ft_issizet(tformat)
{

}
