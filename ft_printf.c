/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:48:02 by ibayandu          #+#    #+#             */
/*   Updated: 2024/10/26 22:48:21 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <libc.h>
#include <limits.h>
#include <stdarg.h>

static char	*show_hex(char *str, int is_upper)
{
	if (is_upper)
		return (ft_strjoin("0X", str));
	return (ft_strjoin("0x", str));
}

static int	nbr_root_sixteen(long number)
{
	int	i;

	i = 1;
	while (number > 16)
	{
		i++;
		number = number / 16;
	}
	return (i);
}

char static	*convert_to_hex(long number, int is_upper)
{
	char	*result;
	char	*hexchars;
	int		loop;

	loop = nbr_root_sixteen(number);
	result = malloc(loop);
	hexchars = "0123456789abcdef";
	while (loop--)
	{
		result[loop] = hexchars[number % 16];
		if (is_upper)
			result[loop] = ft_toupper(result[loop]);
		number /= 16;
	}
	return (result);
}

int static	func_handles(va_list args, char *str)
{
	if (*str == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (*str == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*str == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*str == 'p')
		ft_putstr_fd(show_hex(convert_to_hex(va_arg(args, long), 0), 0), 1);
	else if (*str == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*str == 'u')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*str == 'x')
		ft_putstr_fd(convert_to_hex(va_arg(args, long), 0), 1);
	else if (*str == 'X')
		ft_putstr_fd(convert_to_hex(va_arg(args, long), 1), 1);
	return (0);
}

int static	count_persent(char *ptr)
{
	size_t	count;

	count = 0;
	while (*ptr-- == '%')
		count++;
	return (count);
}

void	print_func(char *str, va_list args)
{
	if (!(count_persent(str - 1) % 2) && *str != '%')
	{
		ft_putchar_fd(*str, 1);
	}
	else if (*str == '%' && *(str + 1) == '%' && (count_persent(str) % 2))
	{
		ft_putchar_fd(*str, 1);
	}
	else if (*str != '%')
		func_handles(args, str);
}

int	ft_printf(const char *str, ...)
{
	char	*s;
	va_list	args;

	va_start(args, str);
	s = (char *)str;
	while (*s)
	{
		print_func(s++, args);
	}
	return (0);
}

int	main(void)
{
	char	str[] = "deneme";

	ft_printf("%c %s %p %d %i %u %x %X %%\n", 'c', "deneme", str, 0x01, 0b0101,
		-14, 0xff, 0xff);
	printf("%c %s %p %d %i %u %x %X %%\n", 'c', "deneme", str, 0x01, 0b0101,
		-14, 0xff, 0xff);
}
