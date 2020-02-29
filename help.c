/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:41:00 by murachid          #+#    #+#             */
/*   Updated: 2020/02/28 18:45:09 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utl_base1(unsigned long long number, int base)
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

void	ft_hex1(unsigned long long number, int xou, t_flags flags)
{
	int k;

	k = 0;
	if (flags.minus == 0)
		help1(number, xou, k, flags);
	else
		help2(number, xou, k, flags);
}
