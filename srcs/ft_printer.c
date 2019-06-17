/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:03:40 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/17 13:17:44 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printer(char *str, t_format *form)
{
	int temp;
	int ret;

	ret = 0;
	if (form == NULL)
		form = ft_newformat();
	if (str == NULL)
		return (0);
	if (form->left_pad != 0)
	{
		temp = form->left_pad;
		temp-=ft_strlen(str);
		if (temp > 0)
		ret += temp;
		while (temp-- > 0)
			ft_putchar(form->pad_type);
	}
	if ( form->space > 0)
	{
		temp = form->space;
		ret += temp;
		while (--temp > 0)
			ft_putchar(' ');
	}
	ft_putstr(str);
	ret += ft_strlen(str);
	if (form->right_pad != 0)
	{
		temp = form->right_pad;
		temp+=ft_strlen(str);
		if (temp < 0)
		ret+= temp * -1;
		while (temp++ < 0)
			ft_putchar(form->pad_type);
	}
	if (form->space < 0)
	{
		temp = form->space;
		ret+= temp * -1;
		while (++temp < 0)
		ft_putchar(' ');
	}
	return (ret);
}
