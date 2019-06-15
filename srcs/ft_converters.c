/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 09:07:56 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/15 14:26:37 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_itoa_base(int n, long base)
{
	int		temp;
	char	*str;
	int		size;

	temp = n;
	size = 0;
	if (n == 0)
		return (strdup("0"));
	while (temp != 0)
	{
		temp = temp / base;
		size++;
	}
	str = ft_strnew(size + 1);
	size--;
	while (size >= 0)
	{
		temp = n % base;
		n = n / base;
		if (temp < 10)
			str[size] = temp + '0';
		else
			str[size] = (temp - 10) + 'a';
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
