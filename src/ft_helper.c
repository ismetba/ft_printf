/* ************************************************************************** */
/*                                                                            */
/*   ft_helper.c                                             :::      ::::::: */
/*                                                         :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: ibayandu <ibayandu@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2024/11/09 13:45:53 by ibayandu             #+#    #+#          */
/*   Updated: 2024/11/09 17:39:21 by ibayandu            ###   ########.tr    */
/*                                                                            */
/*                                 ▗▄▄▄▖▗▄▄▖  ▗▄▖▗▖  ▗▖▗▄▖ ▗▖  ▗▖▗▄▄▄ ▗▖ ▗▖   */
/*                                   █  ▐▌ ▐▌▐▌ ▐▌▝▚▞▘▐▌ ▐▌▐▛▚▖▐▌▐▌  █▐▌ ▐▌   */
/*                                   █  ▐▛▀▚▖▐▛▀▜▌ ▐▌ ▐▛▀▜▌▐▌ ▝▜▌▐▌  █▐▌ ▐▌   */
/*                                 ▗▄█▄▖▐▙▄▞▘▐▌ ▐▌ ▐▌ ▐▌ ▐▌▐▌  ▐▌▐▙▄▄▀▝▚▄▞▘   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_router(va_list va, const char *str, int *total_length)
{
	if (*str == 'p')
		ft_pointer_format(va, total_length);
	else if (*str == 'u')
		ft_unsigned_format(va, total_length);
	else if (*str == 'x' || *str == 'X')
		ft_bonus_dash(va, str, total_length);
	else if (*str == '%')
		ft_putchar('%', total_length);
}

void	ft_init_zero(int *x, int *y)
{
	*x = 0;
	*y = 0;
}
