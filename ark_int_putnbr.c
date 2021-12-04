/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_int_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 08:29:02 by ljohnson          #+#    #+#             */
/*   Updated: 2021/11/30 10:56:22 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ark_printf.h"

int	ark_int_putnbr(int n)
{
	long int	a;
	int			count;

	a = n;
	count = 0;
	if (a < 0)
	{
		count += ark_int_putchar('-');
		a = -a;
	}
	if (a > 9)
	{
		count += ark_int_putnbr(a / 10);
		a %= 10;
	}
	count += ark_int_putchar(a + '0');
	return (count);
}
