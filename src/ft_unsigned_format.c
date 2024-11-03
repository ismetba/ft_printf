/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:12:13 by ibayandu          #+#    #+#             */
/*   Updated: 2024/11/03 19:21:59 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_unsigned_format(va_list args, int *total_length)
{
	unsigned int	u_converted;

	u_converted = va_arg(args, unsigned int);
	if (u_converted == 0)
		ft_putchar('0', total_length);
	else
		ft_putunbr_base(u_converted, "0123456789", total_length);
}
