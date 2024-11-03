#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	i;
	int	j;

	i = printf((" % 1s", ""));
	j = ft_printf((" % 1s", ""));
	printf("%d %d\n", i, j);
}
