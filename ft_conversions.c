/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 08:50:27 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/10 16:15:04 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	ft_ischar(va_list ap, t_format *form)
{
	char	c;
	char	*str;

	c = va_arg(ap, int);
	str = ft_strnew(2);
	str[0] = c;
	ft_printer(str, form);
}

void	ft_isoct(va_list ap, t_format *form)
{
	int		i;
	char	*str;

	i = va_arg(ap, int);
	i = ft_makeunsigned(i);
	str = ft_itoa_base(i, 8);
	ft_printer(str, form);
}

void	ft_ishexi(va_list ap, char c, t_format *form)
{
	int		i;
	char	*str;

	i = va_arg(ap, int);
	i = ft_makeunsigned(i);
	str = ft_itoa_base(i,16);
	if (c == 'X')
		str = ft_makeUpper(str);
	ft_printer(str, form);
}

void	ft_isstring(va_list ap, t_format *form)
{
	char *str;

	str = va_arg(ap, char *);
	ft_printer(str, form);
}
