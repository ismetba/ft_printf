#include "includes/ft_printf.h"
#include <libc.h>

int	main(void)
{
	int	i;
	int	j;

	i = printf(" %p \n", 16);
	j = ft_printf(" %p \n", 16);
	printf("%d %d", i, j);
}
