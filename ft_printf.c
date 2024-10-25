/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:48:02 by ibayandu          #+#    #+#             */
/*   Updated: 2024/10/25 22:31:51 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <libc.h>
#include <limits.h>
#include <stdarg.h>

int static	count_of_persont_sign(char *ptr)
{
	size_t	count;

	count = 0;
	while (*ptr-- == '%')
		count++;
	return (count);
}

void	print_func(char *str, va_list args)
{
	if (!(count_of_persont_sign(str - 1) % 2) && *str != '%')
	{
		ft_putchar_fd(*str, 1);
	}
	else if (*str == '%' && *(str + 1) == '%' && (count_of_persont_sign(str)
			% 2))
		ft_putchar_fd(*str, 1);
	else if (*str != '%')
		ft_putstr_fd(va_arg(args, char *), 1);
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
	ft_printf("aadf %s %sdfsdfsdf%%%%s\n", "deneme", "falan", "filan");
}