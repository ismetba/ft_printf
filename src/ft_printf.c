/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:48:02 by ibayandu          #+#    #+#             */
/*   Updated: 2024/10/31 18:30:05 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <libc.h>
#include <stdarg.h>

static int	u_digit_count(unsigned int nbr)
{
	size_t	counter;

	counter = 0;
	while (nbr > 9)
	{
		nbr /= 10;
		counter++;
	}
	return (counter + 1);
}

static int	digit_count(int nbr)
{
	size_t	counter;

	counter = 0;
	if (nbr < 0)
	{
		counter += 2;
		nbr /= 10;
		nbr *= -1;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		counter++;
	}
	return (counter + 1);
}

static void	ft_uputnbr_fd(unsigned int unbr, int fd)
{
	if (unbr > 9)
		ft_uputnbr_fd(unbr / 10, fd);
	ft_putchar_fd(unbr % 10 + 48, fd);
}

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

// static int	digit_count(void)
// {
// 	return (0);
// }

char static	*convert_to_hex(long number, int is_upper)
{
	char	*result;
	char	*hexchars;
	int		loop;

	loop = nbr_root_sixteen(number);
	result = ft_calloc(loop, sizeof(char));
	if (!result)
		return (NULL);
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
	char	*value;
	char	*p;

	value = va_arg(args, char *);
	if (*str == 's')
	{
		if (value == NULL)
		{
			ft_putstr_fd("(null)",1);
			return (6);
		}	
		ft_putstr_fd(value, 1);
		return (ft_strlen((char *)value));
	}
	else if (*str == 'i')
	{
		ft_putnbr_fd((int)value, 1);
		return (digit_count((int)value));
	}
	else if (*str == 'c')
	{
		ft_putchar_fd((int)value, 1);
		return (1);
	}
	else if (*str == 'p')
	{
		p = show_hex(convert_to_hex((long)value, 0), 0);
		ft_putstr_fd(p, 1);
		return (ft_strlen(p));
	}
	else if (*str == 'd')
	{
		ft_putnbr_fd((int)value, 1);
		return (digit_count((int)value));
	}
	else if (*str == 'u')
	{
		ft_uputnbr_fd((unsigned int)value, 1);
		return (u_digit_count((unsigned int)value));
	}
	else if (*str == 'x')
	{
		p = convert_to_hex((long)value, 0);
		ft_putstr_fd(p, 1);
		return (ft_strlen(p));
	}
	else if (*str == 'X')
	{
		p = convert_to_hex((long)value, 1);
		ft_putstr_fd(p, 1);
		return (ft_strlen(p));
	}
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

int	print_func(char *str, va_list args)
{
	if (!(count_persent(str - 1) % 2) && *str != '%')
	{
		ft_putchar_fd(*str, 1);
		return (1);
	}
	else if (*str == '%' && *(str + 1) == '%' && (count_persent(str) % 2))
	{
		ft_putchar_fd(*str, 1);
		return (1);
	}
	else if (*str != '%')
	{
		return (func_handles(args, str));
	}
	else if (ft_isprint(*str) && *str != '%')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	char	*s;
	size_t	counter;
	va_list	args;

	counter = 0;
	va_start(args, str);
	s = (char *)str;
	while (*s)
	{
		counter += print_func(s++, args);
	}
	return (counter);
}
