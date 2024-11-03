/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:11:37 by ibayandu          #+#    #+#             */
/*   Updated: 2024/11/03 19:22:17 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_pointer_format(va_list args, int *total_length)
{
	unsigned long	u_converted;

	u_converted = va_arg(args, unsigned long);
	if (u_converted == 0)
		ft_putstr("(nil)", total_length);
	else
	{
		ft_putstr("0x", total_length);
		ft_putlnbr_base(u_converted, "0123456789abcdef", total_length);
	}
}