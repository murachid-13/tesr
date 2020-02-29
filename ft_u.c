/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:22:06 by murachid          #+#    #+#             */
/*   Updated: 2020/02/20 12:22:08 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_input_uint(char *u_num, t_flags flags)
{
	if (flags.dot >= 0)
		width(flags.dot, ft_strlen(u_num), 1);
	ft_putstr(u_num, ft_strlen(u_num));
}

void	ft_put_uint(char *u_num, t_flags flags)
{
	if (flags.minus == 1)
		ft_input_uint(u_num, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(u_num))
		flags.dot = ft_strlen(u_num);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		width(flags.width, 0, 0);
	}
	else
		width(flags.width, ft_strlen(u_num), flags.zero);
	if (flags.minus == 0)
		ft_input_uint(u_num, flags);
}

void	ft_u(unsigned int number, t_flags flags)
{
	char	*ptr;
	int		k;

	k = 0;
	if (flags.dot == 0 && number == 0)
	{
		k = 1;
		width(flags.width, 0, 0);
	}
	if (k == 0)
	{
		ptr = ft_u_itoa(number);
		ft_put_uint(ptr, flags);
		free(ptr);
	}
}
