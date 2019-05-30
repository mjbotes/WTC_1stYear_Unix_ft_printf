/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 09:07:56 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/30 13:12:17 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
