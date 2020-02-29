/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:21:52 by murachid          #+#    #+#             */
/*   Updated: 2020/02/20 12:21:55 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pint(char *str, int nbr, t_flags flags)
{
	if (flags.dot >= 0 && nbr < 0 && nbr != -2147483648)
		ft_putchar('-');
	if (flags.dot >= 0)
		width(flags.dot, ft_strlen(str), 1);
	ft_putstr(str, ft_strlen(str));
}

void	ft_int(char *str, int num, t_flags flags)
{
	if (flags.minus == 1)
		ft_pint(str, num, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str) && num != 0)
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		width(flags.width, 0, 0);
	}
	else
		width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		ft_pint(str, num, flags);
}

void	ft_print_int(int i, t_flags flags)
{
	int		j;
	char	*str;
	int		k;

	k = 0;
	j = i;
	if (flags.dot == 0 && i == 0)
	{
		width(flags.width, 0, 0);
		k = 1;
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1) && i != -2147483648)
	{
		if ((flags.dot <= -1 && flags.zero == 1))
			ft_putchar('-');
		i *= -1;
		flags.width--;
	}
	if (k == 0)
	{
		str = ft_itoa(i);
		ft_int(str, j, flags);
		free(str);
	}
}
