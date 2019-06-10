/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 07:34:28 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/10 16:14:11 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

struct		s_format
{
	int 	right_pad;
	int 	left_pad;
	char	pad_type;
	char	*format;
}typedef	t_format;

int			ft_makeunsigned(int num);
char		*ft_makeUpper(char *str);
char		*ft_itohexi(int n);
char		*ft_itooctal(int n);
void 		ft_ischar(va_list ap, t_format *form);
void		ft_isoct(va_list ap, t_format *form);
void		ft_ishexi(va_list ap, char c, t_format *form);
void		ft_isunicode(va_list ap, t_format *form);
void		ft_isstring(va_list ap, t_format *form);
void		ft_isint(va_list ap, t_format *form);
void		ft_isuint(va_list ap, t_format *form);
int			ft_isidentifier(char c);
void		ft_identifier(char c, va_list ap, t_format *form);
int			ft_isflag(char c);
void		ft_flag(char **c, t_format *form);
void		ft_justify(char **c, t_format *form);
void		ft_hashtag();
int			ft_ischardesc(char c);
void		ft_chardesc(char **c, t_format *form);
int			ft_charint(t_format *form);
int			ft_shortint(t_format *form);
int			ft_longint(t_format *form);
int			ft_intmax(t_format *form);
int			ft_sizet(t_format *form);
int			ft_printf(const char *format, ...);
t_format	*ft_newformat();
void		ft_delformat(t_format **ptr);
void	ft_printer(char *str, t_format *form);
char	*ft_itoa_base(int n, int base);
