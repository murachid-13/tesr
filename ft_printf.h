/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:57:29 by murachid          #+#    #+#             */
/*   Updated: 2020/02/29 10:41:18 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_flags
{
	int			star;
	int			zero;
	int			minus;
	int			width;
	int			dot;
	int			type;
}				t_flags;

int				g_len;
void			ft_hex_input1(char *hex);
void			ft_put_hex1(char *hex, t_flags flags);
char			*ft_base(unsigned long long number, int base,
int count, char *str);
char			*ft_utl_base1(unsigned long long number, int base);
void			ft_hex1(unsigned long long number, int xou, t_flags flags);
void			help2(unsigned long long number, int xou, int k, t_flags flags);
void			help1(unsigned long long number, int xou, int k, t_flags flags);
void			ft_input_pointeur(char *pointer, t_flags flags);
int				ft_intlen(long n);
char			*ft_strdup(const char *s1);
void			ft_put_uint(char *u_num, t_flags flags);
void			ft_u(unsigned int number, t_flags flags);
void			ft_input_uint(char *u_num, t_flags flags);
char			*ft_u_itoa(unsigned long long n);
char			*ft_generate(char *nc, long num, int length, int neg);
void			ft_char(char c, t_flags flags);
void			ft_input_string(char *str, t_flags flags);
void			ft_string(char *str, t_flags flags);
void			ft_input(const char *str, va_list args);
t_flags			ft_initialize(void);
int				ft_test_flags(const char *str, int i,
t_flags *flags, va_list args);
void			ft_input(const char *str, va_list args);
int				ft_printf(const char *tab, ...);
void			width(int width, int minus, int zero);
void			ft_percent(t_flags flags);
void			ft_char(char c, t_flags flags);
t_flags			ft_minus(t_flags flags);
t_flags			ft_digit(char c, t_flags flags);
t_flags			ft_width(va_list args, t_flags flags);
int				ft_dot(const char *str, int start,
t_flags *flags, va_list args);
void			ft_pint(char *str, int num, t_flags flags);
void			ft_print_int(int i, t_flags flags);
void			ft_int(char *str, int num, t_flags flags);
int				ft_putstr(char *str, int precision);
int				ft_flag(int c);
int				ft_dicsxp(int c);
void			ft_print(int c, t_flags flags, va_list args);
void			width(int width, int minus, int zero);
char			*ft_strdup(const char *s1);
int				ft_intlen(long n);
char			*ft_generate(char *nc, long num, int length, int neg);
void			ft_putchar(char c);
int				ft_size(int n);
char			*ft_itoa(int nb);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *str);
void			ft_hex(unsigned int number, int lowercase, t_flags flags);
void			ft_put_hex(char *hex, t_flags flags);
void			ft_hex_input(char *hex, t_flags flags);
char			*ft_utl_base(unsigned long long number, int base);
char			*ft_str_tolower(char *str);
int				ft_tolower(int c);

#endif
