/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:22:25 by murachid          #+#    #+#             */
/*   Updated: 2020/02/20 12:22:27 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(char c, t_flags flags)
{
	if (flags.minus == 1)
		ft_putchar(c);
	width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
}

void	ft_input_string(char *str, t_flags flags)
{
	if (flags.dot >= 0)
	{
		width(flags.dot, ft_strlen(str), 0);
		ft_putstr(str, flags.dot);
	}
	else
		ft_putstr(str, ft_strlen(str));
}

void	ft_string(char *str, t_flags flags)
{
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		ft_input_string(str, flags);
	if (flags.dot >= 0)
		width(flags.width, flags.dot, 0);
	else
		width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		ft_input_string(str, flags);
}
