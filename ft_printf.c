/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:57:50 by murachid          #+#    #+#             */
/*   Updated: 2020/02/19 13:57:52 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *tab, ...)
{
	va_list		args;

	g_len = 0;
	va_start(args, tab);
	ft_input(tab, args);
	va_end(args);
	return (g_len);
}
