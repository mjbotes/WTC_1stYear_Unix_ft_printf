/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 08:50:27 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/17 15:30:01 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_ischar(va_list ap, t_format *form)
{
	char	c;
	char	*str;
	int		ret;

	c = va_arg(ap, int);
	str = ft_strnew(2);
	str[0] = c;
	return (ft_printer(str, form));
}

int	ft_isoct(va_list ap, t_format *form)
{
	long		i;
	char	*str;

	i = va_arg(ap, long);
	str = ft_itoa_base(i, 8);
	return (ft_printer(str, form));
}

int	ft_ishexi(va_list ap, char c, t_format *form)
{
	long		i;
	char	*str;

	i = va_arg(ap, long);
	str = ft_itoa_base(i,16);
	if (c == 'X')
		str = ft_makeUpper(str);
	return(ft_printer(str, form));
}

int	ft_isstring(va_list ap, t_format *form)
{
	char *str;

	str = va_arg(ap, char *);
	return(ft_printer(str, form));
}
