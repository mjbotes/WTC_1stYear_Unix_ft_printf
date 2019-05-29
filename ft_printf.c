/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:32:29 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/29 16:36:37 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

int		ft_makeunsigned(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

char	*ft_makeUpper(char *str)
{
	int	loop;

	loop = -1;
	while (str[++loop] != '\0')
		str[loop] = ft_toupper(str[loop]);
	return (str);
}

char	*ft_itohexi(int n)
{
	int		temp;
	char	*str;
	int		size;

	temp = n;
	size = 0;
	while (temp > 1)
	{
		temp = temp / 16;
		size++;
	}
	str = ft_strnew(size + 1);
	size--;
	while (size >= 0)
	{
		temp = n % 16;
		n = n / 16;
		if (temp < 10)
			str[size] = temp + '0';
		else
			str[size] = temp - 10 + 'a';
		size--;
	}
	return (str);
}

char	*ft_itooctal(int n)
{
	int		temp;
	char	*str;
	int		size;

	temp = n;
	size = 0;
	while (temp > 1)
	{
		temp = temp / 8;
		size++;
	}
	str = ft_strnew(size + 1);
	size--;
	while (size >= 0)
	{
		temp = n % 8;
		n = n / 8;
		str[size] = temp + '0';
		size--;
	}
	return (str);
}

void 	ft_ischar(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar(c);
}

void	ft_isoct(va_list ap)
{
	int		i;
	char	*str;

	i = va_arg(ap, int);
	i = ft_makeunsigned(i);
	str = ft_itooctal(i);
	ft_putstr(str);
}

void	ft_ishexi(va_list ap, char c)
{
	int		i;
	char	*str;

	i = va_arg(ap, int);
	i = ft_makeunsigned(i);
	str = ft_itohexi(i);
	if (c == 'X')
		str = ft_makeUpper(str);
	ft_putstr(str);
}

void	ft_isunicode(va_list ap)
{
	ap;
}

void	ft_isstring(va_list ap)
{
	char *str;

	str = va_arg(ap, char *);
	ft_putstr(str);
}

void	ft_isint(va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	ft_putnbr(num);
}

void	ft_isuint(va_list ap)
{
	int	num;
	
	num = va_arg(ap, int);
	num = ft_makeunsigned(num);
	ft_putnbr(num);
}

void	ft_identifier(char c, va_list ap)
{
	if (c == 's')
		ft_isstring(ap);
	if (c == 'i' || c == 'd')
		ft_isint(ap);
	if (c == 'u')
		ft_isuint(ap);
	if (c == 'o' || c == 'O')
		ft_isoct(ap);
	if (c == 'x' || c == 'X')
		ft_ishexi(ap, c);
	if (c == 'c')
		ft_ischar(ap);
	if (c == 'C')
		ft_isunicode(ap);
	if (c == '%')
		ft_putchar('%');
}

int		ft_isflag(char c, va_list ap, s_flag flag)
{
	if (c == '0')
	
	if (c == '+')
	
	if (c == '#')

	if (c == ' ')

	if (c == 'h')
		if (flags->prev == 'h')

		else

	if (c == 'l')
		if (flags->prev == 'l')

		else

	if (c == 'j')
	
	if (c == 'z')
		
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*tmp;
	char	*str;
	int		loop;

	va_start(ap, format);
	loop = 0;
	str = ft_strdup(format);
	while (str[loop] != '\0')
	{
		if (str[loop] == '%')
		{
			tmp = ft_strdup(&str[loop]);
			str[loop] = '\0';
			ft_putstr(str);
			ft_strdel(&str);
			str = strdup(tmp + 2);
			loop = 0;
			ft_identifier(tmp[1], ap);
			ft_strdel(&tmp);
		}
		loop++;
	}
	ft_putstr(str);
	va_end(ap);
	return (0);
}

int		main()
{
	ft_printf("test 1 :%s my name is %s and i am %%", "hi", "marnus", 4);
}
