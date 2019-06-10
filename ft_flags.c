/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 08:33:43 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/10 16:01:27 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (*(c[0]) == '0')
	{
		loop = 1;
		form->pad_type = *(c[0]);
	}
	if (*(c[0]) == ' ')
		loop = 1;
	if (*(c[loop]) == '+' || *(c[loop]) == '-')
		loop++;
	while (ft_isdigit(*c[loop]))
			loop ++;
	if (loop != 0)
	{
		str = ft_strsub(*c, 0, loop);
		num = ft_atoi(str);
		if (num < 0)
			form->left_pad = num;
		if (num > 0)
			form->right_pad = num;
		if (*(c[0]) == ' ')
		{
			form->right_pad -= 1;
		}	
		ft_strdel(&str);
		str = ft_strdup(*(c) + loop);
		ft_strdel(c);
		*c = ft_strdup(str);
	}
}

void	ft_isintmax(t_format form)
{

}

void	ft_issizet(tformat)
{

}
