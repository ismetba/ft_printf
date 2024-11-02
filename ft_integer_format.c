/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:11:34 by ibayandu          #+#    #+#             */
/*   Updated: 2024/11/02 22:13:03 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_integer_format(int *total_length, int i_converted)
{
	if (i_converted == 0)
		ft_putchar('0', total_length);
	else
		ft_putnbr(i_converted, total_length);
}
