/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:36:21 by ljohnson          #+#    #+#             */
/*   Updated: 2021/11/30 19:39:12 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define UHEX "0123456789ABCDEF"
# define LHEX "0123456789abcdef"
# define BDEC "0123456789"
# define CSET "scdiuxXp"

int	ark_printf(const char *format, ...);
int	ark_int_putchar(int c);
int	ark_int_putstr(char *s);
int	ark_int_putnbr(int n);
int	ark_int_strlen(const char *str);
int	ark_int_putnbr_base(unsigned int nbr, char *base);
int	ark_int_putptr(unsigned long long nbr);

#endif