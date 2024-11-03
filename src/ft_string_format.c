/* ************************************************************************** */
/*                                                                            */
/*   ft_string_format.c                                      :::      ::::::: */
/*                                                         :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: ibayandu <ibayandu@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2024/11/03 21:57:03 by ibayandu             #+#    #+#          */
/*   Updated: 2024/11/03 22:07:18 by ibayandu            ###   ########.tr    */
/*                                                                            */
/*                                 ▗▄▄▄▖▗▄▄▖  ▗▄▖▗▖  ▗▖▗▄▖ ▗▖  ▗▖▗▄▄▄ ▗▖ ▗▖   */
/*                                   █  ▐▌ ▐▌▐▌ ▐▌▝▚▞▘▐▌ ▐▌▐▛▚▖▐▌▐▌  █▐▌ ▐▌   */
/*                                   █  ▐▛▀▚▖▐▛▀▜▌ ▐▌ ▐▛▀▜▌▐▌ ▝▜▌▐▌  █▐▌ ▐▌   */
/*                                 ▗▄█▄▖▐▙▄▞▘▐▌ ▐▌ ▐▌ ▐▌ ▐▌▐▌  ▐▌▐▙▄▄▀▝▚▄▞▘   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_string_format(va_list args, int *total_length, int space)
{
	char	*string_ptr;

	string_ptr = va_arg(args, char *);
	if (space && ft_strncmp(string_ptr, "", ft_strlen(string_ptr)) == 0)
		ft_putstr("", total_length);
	else if (string_ptr == NULL)
		ft_putstr("(null)", total_length);
	else
		ft_putstr(string_ptr, total_length);
}
