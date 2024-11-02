/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:11:30 by ibayandu          #+#    #+#             */
/*   Updated: 2024/11/02 22:13:05 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_hex_format(char c, int *total_length, unsigned int u_converted)
{
	if (c == 'x')
		ft_putunbr_base(u_converted, "0123456789abcdef", total_length);
	else
		ft_putunbr_base(u_converted, "0123456789ABCDEF", total_length);
}
