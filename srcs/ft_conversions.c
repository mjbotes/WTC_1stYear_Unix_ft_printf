/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 08:50:27 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/29 13:22:24 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_ischar(va_list ap, char ch, t_format *form)
{
	char	c;
	char	*str;
	int		ret;
	
	if (form->format[0] == 'l')
	{
		ft_putchar((char)va_arg(ap, void *));
		return (1);
	}
	else
		c = va_arg(ap, int);
	if (c == 0)
		form->type = 'n';
	else
		form->type = 's';
	str = ft_strnew(2);
	str[0] = c;
	return (ft_printer(str, form));
}

int	ft_isOct(va_list ap, t_format *form)
{
	uintmax_t	i;
	char	*str;
	form->type = 'o';
	i = va_arg(ap, uintmax_t);
	str = ft_itoa_base(i, 8);
	return (ft_printer(str, form));
}

int	ft_isoct(va_list ap, t_format *form)
{
	unsigned int	i;
	char	*str;
	form->type = 'o';
	if (form->format != NULL)
	{
		if (ft_strcmp(form->format, "hh") == 0)
			return (ft_printer(ft_itoa_base((unsigned char)va_arg(ap, unsigned int), 8), form));
		else if (ft_strcmp(form->format, "h") == 0)
			return (ft_printer(ft_itoa_base((unsigned short)va_arg(ap, unsigned long), 8), form));
		else if (ft_strcmp(form->format, "l") == 0)
			 return (ft_printer(ft_itoa_base((unsigned long)va_arg(ap, unsigned long), 8),form));
		else if (ft_strcmp(form->format, "ll") == 0)
			 return (ft_printer(ft_itoa_base((unsigned long long)va_arg(ap, unsigned long long), 8),form));
		else if (ft_strcmp(form->format, "j") == 0)
			 return (ft_printer(ft_itoa_base((uintmax_t)va_arg(ap, uintmax_t), 8),form));
		else if (ft_strcmp(form->format, "z") == 0)
			 return (ft_printer(ft_itoa_base((size_t)va_arg(ap, size_t), 8),form));
	}	
	i = va_arg(ap, unsigned int);
	str = ft_itoa_base(i, 8);
	return (ft_printer(str, form));
}

int	ft_ishexi(va_list ap, char c, t_format *form)
{
	long		i;
	char	*str;

	if (form->format != NULL)
	{
		if (ft_strcmp(form->format, "hh") == 0)
			str = ft_itoa_base((unsigned char)va_arg(ap, unsigned int), 16);
		else if (ft_strcmp(form->format, "h") == 0)
			str = ft_itoa_base((unsigned short)va_arg(ap, unsigned long), 16);
		else if (ft_strcmp(form->format, "l") == 0)
			 str = ft_itoa_base((unsigned long)va_arg(ap, unsigned long), 16);
		else if (ft_strcmp(form->format, "ll") == 0)
			 str = ft_itoa_base((unsigned long long)va_arg(ap, unsigned long long), 16);
		else if (ft_strcmp(form->format, "j") == 0)
			 str = ft_itoa_base((uintmax_t)va_arg(ap, uintmax_t), 16);
		else if (ft_strcmp(form->format, "z") == 0)
			 str = ft_itoa_base((size_t)va_arg(ap, size_t), 16);
	}	
	else  
		str = ft_itoa_base(va_arg(ap, unsigned int), 16);
	form->type = 'x';
	if (c == 'X')
	{
		str = ft_makeUpper(str);
		form->type = 'X';
	}
	return (ft_printer(str, form));
}

int	ft_isstring(va_list ap, t_format *form)
{
	char *str;

	str = va_arg(ap, char *);
	form->type = 's';
	if (str == NULL)
		str = ft_strdup("(null)");
	return(ft_printer(str, form));
}

int	ft_isString(va_list ap, t_format *form)
{
	char	*str;
	int		loop;

	loop = 0;
	str = va_arg(ap, wchar_t *);
	form->type = 's';
	if (str == NULL)
		str = ft_strdup("(null)");
	while (str[loop] != '\0')
		loop++;
}
