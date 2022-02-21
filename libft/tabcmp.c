#include "libft.h"

int	tabcmp(int *tab, int *arr, int n)
{
	int i;

	i = -1;
	while (++i < n)
	{
		if (tab[i] != arr[i])
			return (0);
	}
	return (1);
}
