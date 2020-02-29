/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:22:34 by murachid          #+#    #+#             */
/*   Updated: 2020/02/20 12:22:36 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex_input(char *hex, t_flags flags)
{
	if (flags.dot >= 0)
		width(flags.dot, ft_strlen(hex), 1);
	ft_putstr(hex, ft_strlen(hex));
}

void	ft_put_hex(char *hex, t_flags flags)
{
	if (flags.minus == 1)
		ft_hex_input(hex, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hex))
		flags.dot = ft_strlen(hex);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		width(flags.width, 0, 0);
	}
	else
		width(flags.width, ft_strlen(hex), flags.zero);
	if (flags.minus == 0)
		ft_hex_input(hex, flags);
}

char	*ft_base(unsigned long long number, int base,
int count, char *str)
{
	while (number != 0)
	{
		if ((number % base) < 10)
			str[count - 1] = (number % base) + 48;
		else
			str[count - 1] = (number % base) + 55;
		number /= base;
		count--;
	}
	return (str);
}

char	*ft_utl_base(unsigned long long number, int base)
{
	unsigned long long	temp;
	int					i;
	char				*str;

	temp = number;
	str = 0;
	i = 0;
	if (number == 0)
		return (ft_strdup("0"));
	while (number != 0)
	{
		number /= base;
		i++;
	}
	if (!(str = malloc(i + 1)))
		return (0);
	str[i] = '\0';
	str = ft_base(temp, base, i, str);
	return (str);
}

void	ft_hex(unsigned int number, int xou, t_flags flags)
{
	char	*hex;
	int		k;

	k = 0;
	if (flags.dot == 0 && number == 0)
	{
		width(flags.width, 0, 0);
		k = 1;
	}
	if (k == 0)
	{
		hex = ft_utl_base((unsigned long long)number, 16);
		if (xou == 1)
			hex = ft_str_tolower(hex);
		ft_put_hex(hex, flags);
		free(hex);
	}
}
