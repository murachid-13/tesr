/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:24:11 by murachid          #+#    #+#             */
/*   Updated: 2020/02/28 18:53:47 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_percent(t_flags flags)
{
	if (flags.minus == 1)
		ft_putchar('%');
	width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		ft_putchar('%');
}

void	ft_wrt(void)
{
	ft_putchar('0');
	ft_putchar('x');
}

void	help1(unsigned long long number, int xou, int k, t_flags flags)
{
	char	*s;
	char	*hex;
	int		len;

	if (flags.width != 0)
	{
		s = ft_utl_base1(number, 16);
		len = flags.width - (ft_strlen(s) + 2);
		free(s);
		width(len, 0, 0);
	}
	ft_wrt();
	if (flags.dot == 0 && number == 0)
	{
		width(flags.width - ft_strlen(s), 0, 0);
		k = 1;
	}
	if (k == 0)
	{
		hex = ft_utl_base1((unsigned long long)number, 16);
		if (xou == 1)
			hex = ft_str_tolower(hex);
		ft_putstr(hex, ft_strlen(hex));
		free(hex);
	}
}

void	help2(unsigned long long number, int xou, int k, t_flags flags)
{
	char	*s;
	char	*hex;
	int		len;

	ft_wrt();
	if (flags.dot == 0 && number == 0)
	{
		width(flags.width - ft_strlen(s), 0, 0);
		k = 1;
	}
	if (k == 0)
	{
		hex = ft_utl_base1((unsigned long long)number, 16);
		if (xou == 1)
			hex = ft_str_tolower(hex);
		ft_putstr(hex, ft_strlen(hex));
		free(hex);
	}
	if (flags.width != 0)
	{
		s = ft_utl_base1(number, 16);
		len = flags.width - (ft_strlen(s) + 2);
		free(s);
		width(len, 0, 0);
	}
}
