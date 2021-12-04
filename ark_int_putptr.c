/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_int_putptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:36:52 by ljohnson          #+#    #+#             */
/*   Updated: 2021/11/30 19:38:31 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ark_printf.h"

static int	ark_int_putptr_base(unsigned long long nbr, char *base)
{
	int					count;
	unsigned long long	hexptr;
	size_t				baselen;

	count = 0;
	hexptr = nbr;
	baselen = ark_int_strlen(base);
	if (hexptr >= baselen)
		count += ark_int_putptr_base(hexptr / baselen, base);
	count += ark_int_putchar(base[hexptr % baselen]);
	return (count);
}

int	ark_int_putptr(unsigned long long nbr)
{
	int	count;

	count = 0;
	count += ark_int_putstr("0x");
	count += ark_int_putptr_base(*(unsigned long long *)&nbr, LHEX);
	return (count);
}
