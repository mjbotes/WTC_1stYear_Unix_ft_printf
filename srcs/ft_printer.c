/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:03:40 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/18 15:16:34 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_zeropad(char **str, t_format *form)
{
	char	*tmp;
	int		temp;
	int		zero;
	int		loop;

	temp = ft_strlen(*str);
	zero = 0;
	loop = 0;
	if (form->zeropad != -1)
	{
		while ((*str)[--temp] == '0')
			zero++;
		if (form->zeropad  <= zero)
			(*str)[form->zeropad + temp + 1] = '\0';
		else 
		{
			tmp = ft_strnew(temp + form->zeropad + 1);
			ft_strncat(tmp , *str, temp + 1);
			while (loop++ < form->zeropad)
				tmp[temp + loop] = '0';
			ft_strdel(str);
			*str = ft_strdupdel(&tmp);
		}
	}
}

int	ft_printer(char *str, t_format *form)
{
	int temp;
	int ret;
	int	zero;
	char *tmp;
	int	loop;

	ret = 0;
	if (form == NULL)
		form = ft_newformat();
	if (str == NULL)
		return (0);
	ft_zeropad(&str, form);
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
	if (form->plus)
		ft_putchar('+');
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
