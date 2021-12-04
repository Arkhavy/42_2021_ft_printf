/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_int_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:40:33 by ljohnson          #+#    #+#             */
/*   Updated: 2021/11/30 09:19:16 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ark_printf.h"

int	ark_int_putstr(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		write(1, s, ark_int_strlen(s));
	return (ark_int_strlen(s));
}
