/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:22:47 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/04 11:16:10 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ark_printf.h"

static int	ark_print_parse(va_list ap, char fc)
{
	int	count;

	count = 0;
	if (fc == 's')
		count += ark_int_putstr(va_arg(ap, char *));
	else if (fc == 'c')
		count += ark_int_putchar(va_arg(ap, int));
	else if (fc == 'd')
		count += ark_int_putnbr(va_arg(ap, int));
	else if (fc == 'i')
		count += ark_int_putnbr(va_arg(ap, int));
	else if (fc == 'u')
		count += ark_int_putnbr_base(va_arg(ap, unsigned int), BDEC);
	else if (fc == 'x')
		count += ark_int_putnbr_base(va_arg(ap, unsigned int), LHEX);
	else if (fc == 'X')
		count += ark_int_putnbr_base(va_arg(ap, unsigned int), UHEX);
	else if (fc == 'p')
		count += ark_int_putptr((unsigned long long)va_arg(ap, void *));
	return (count);
}

static int	is_charset(char fc)
{
	size_t	a;

	a = 0;
	while (CSET[a])
	{
		if (fc == CSET[a])
			return (1);
		a++;
	}
	return (0);
}

int	ark_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	size_t	a;

	count = 0;
	a = 0;
	va_start(ap, format);
	while (format[a])
	{
		if (format[a] == '%')
		{
			a++;
			if (format[a] == '%')
				count += ark_int_putchar(format[a]);
			else if (is_charset(format[a]))
				count += ark_print_parse(ap, format[a]);
			else if (!format[a])
				break ;
		}
		else
			count += ark_int_putchar(format[a]);
		a++;
	}
	va_end(ap);
	return (count);
}
