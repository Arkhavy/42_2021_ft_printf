/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_int_putnbr_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:31:02 by ljohnson          #+#    #+#             */
/*   Updated: 2021/11/30 19:22:13 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ark_printf.h"

int	ark_int_putnbr_base(unsigned int nbr, char *base)
{
	int				count;
	unsigned int	hexnb;
	size_t			baselen;

	count = 0;
	hexnb = nbr;
	baselen = ark_int_strlen(base);
	if (hexnb >= baselen)
		count += ark_int_putnbr_base(hexnb / baselen, base);
	count += ark_int_putchar(base[hexnb % baselen]);
	return (count);
}
