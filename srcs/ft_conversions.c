/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 08:50:27 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/18 15:49:46 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_ischar(va_list ap, t_format *form)
{
	unsigned char	c;
	char	*str;
	int		ret;
	
//	form->type = strdup("str");
	c = va_arg(ap, int);
	ft_putchar(c);
	return (1);
}

int	ft_isoct(va_list ap, t_format *form)
{
	long long	i;
	char	*str;
	
	if (ft_strcmp(form->format, "hh") == 0)
		i = (unsigned char)va_arg(ap, unsigned int);
	else if (ft_strcmp(form->format, "h") == 0)
		i = (unsigned short)va_arg(ap, unsigned int);
	else if (ft_strcmp(form->format, "l") == 0)
		 return (ft_printer(ft_itoa_base((unsigned long)va_arg(ap, unsigned long), 8),form));
	else if (ft_strcmp(form->format, "ll") == 0)
		 return (ft_printer(ft_itoa_base((unsigned long long)va_arg(ap, unsigned long long), 8),form));
	else if (ft_strcmp(form->format, "j") == 0)
		 return (ft_printer(ft_itoa_base((uintmax_t)va_arg(ap, uintmax_t), 8),form));
	else if (ft_strcmp(form->format, "z") == 0)
		 return (ft_printer(ft_itoa_base((size_t)va_arg(ap, size_t), 8),form));
	else
		i = va_arg(ap, long long);
	str = ft_itoa_base(i, 8);
	return (ft_printer(str, form));
}

int	ft_ishexi(va_list ap, char c, t_format *form)
{
	long		i;
	char	*str;

	i = va_arg(ap, long);
//	form->type = strdup("dig");
	str = ft_itoa_base(i,16);
	if (c == 'X')
		str = ft_makeUpper(str);
	return(ft_printer(str, form));
}

int	ft_isstring(va_list ap, t_format *form)
{
	char *str;

	str = va_arg(ap, char *);
//	form->type = strdup("str");
	if (str == NULL)
		str = ft_strdup("(null)");
	return(ft_printer(str, form));
}
