/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:48:09 by murachid          #+#    #+#             */
/*   Updated: 2020/02/28 18:48:37 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int nb)
{
	char	*str;
	long	nbr;
	int		i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * ft_size(nb) + 1)))
		return (NULL);
	if (nb < 0)
		str[0] = '-';
	nbr = nb;
	if (nbr < 0)
		nbr = -nbr;
	str[ft_size(nb) - i++] = '\0';
	while (nbr >= 10)
	{
		str[ft_size(nb) - i++] = (nbr % 10) + 48;
		nbr /= 10;
	}
	str[ft_size(nb) - i++] = (nbr % 10) + 48;
	return (str);
}

int		ft_intlen(long n)
{
	size_t	length;
	int		neg;

	length = 0;
	neg = 0;
	if (n < 0)
	{
		length++;
		neg++;
		n = -n;
	}
	while (n >= 1)
	{
		length++;
		n /= 10;
	}
	return (length);
}

char	*ft_generate(char *nc, long num, int length, int neg)
{
	if (num != 0)
		nc = malloc(sizeof(char) * (length + 1));
	else
		return (nc = ft_strdup("0"));
	if (!nc)
		return (0);
	neg = 0;
	if (num < 0)
	{
		neg++;
		num = -num;
	}
	nc[length] = '\0';
	while (--length)
	{
		nc[length] = (num % 10) + '0';
		num /= 10;
	}
	if (neg == 1)
		nc[0] = '-';
	else
		nc[0] = (num % 10) + '0';
	return (nc);
}

char	*ft_u_itoa(unsigned long long n)
{
	int		length;
	char	*nc;
	long	num;
	int		neg;

	num = n;
	length = ft_intlen(num);
	nc = 0;
	neg = 0;
	if (!(nc = ft_generate(nc, num, length, neg)))
		return (0);
	return (nc);
}

char	*ft_strdup(const char *s1)
{
	int		c;
	char	*dest;

	c = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[c] != '\0')
	{
		dest[c] = s1[c];
		c++;
	}
	dest[c] = '\0';
	return (dest);
}
