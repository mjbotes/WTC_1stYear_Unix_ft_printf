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
		if (form->type != NULL && ft_strcmp(form->type,"ptr") == 0)
		{
			tmp = ft_strchr(*str, 'x');
			loop = ft_strlen(tmp);
			if ( loop < form->zeropad)
			{
				tmp = ft_strnew(2 + form->zeropad);
				tmp = ft_strncat(tmp, *str, 2);
				while (zero++ <= form->zeropad - loop)
					tmp[zero + 1] = '0';
				ft_strcat(&tmp[zero + 1], &(*str)[2]);
				*str = ft_strdupdel(&tmp);
			}
                	else
			{
			        while((*str)[--temp] == '0')
                        zero++;
                        (*str)[form->zeropad + temp + 1] = '\0';
		}
}
	else {				
		if (form->zeropad > temp)
		{
			tmp = ft_strnew(form->zeropad);
			while (zero < form->zeropad - temp)
				tmp[zero++] = '0';
			ft_strcat(&tmp[zero],*str);
			*str = ft_strdupdel(&tmp);
		}
	}
}}

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
