/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:03:28 by murachid          #+#    #+#             */
/*   Updated: 2020/02/20 11:03:30 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_test_flags(const char *str, int i, t_flags *flags, va_list args)
{
	i = i + 1;
	while (str[i])
	{
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '*')
			*flags = ft_width(args, *flags);
		if (str[i] == '.')
			i = ft_dot(str, i, flags, args);
		if (str[i] == '-')
			*flags = ft_minus(*flags);
		if (ft_isdigit(str[i]))
			*flags = ft_digit(str[i], *flags);
		if (ft_dicsxp(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

void	ft_input(const char *str, va_list args)
{
	int		i;
	t_flags	flags;

	i = 0;
	while (str != '\0')
	{
		flags = ft_initialize();
		if (!str[i])
			break ;
		else if (str[i] != '%')
			ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			i = ft_test_flags(str, i, &flags, args);
			if (ft_dicsxp(str[i]))
				ft_print((char)flags.type, flags, args);
		}
		i++;
	}
}

int		ft_dicsxp(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
	|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int		ft_flag(int c)
{
	return ((c == '.') || (c == '*') || (c == '0') || (c == '-') || (c == ' '));
}

void	ft_print(int c, t_flags flags, va_list args)
{
	int i;

	i = 0;
	if ((c == 'i') || (c == 'd'))
		ft_print_int(va_arg(args, int), flags);
	else if (c == 'c')
		ft_char(va_arg(args, int), flags);
	else if (c == '%')
		ft_percent(flags);
	else if (c == 'p')
		ft_hex1(va_arg(args, unsigned long long), 1, flags);
	else if (c == 's')
		ft_string(va_arg(args, char *), flags);
	else if (c == 'x')
		ft_hex(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		ft_hex(va_arg(args, unsigned int), 0, flags);
	else if (c == 'u')
		ft_u(va_arg(args, unsigned int), flags);
}
