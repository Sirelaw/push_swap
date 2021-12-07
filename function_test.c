#include <unistd.h>
#include "libft/libft.h"

int smallest(int *arr, int size)//Ok
{
	int i;
	int	j;
	int min;
	
	min = arr[0];
	i = 0;
	j = 0;
	while (i < size)
	{
		if (min > arr[i])
		{
			min = arr[i];
			j = i;
		}
		i++;
	}
	return (j);
}

int smaller(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

int main(int argc, char **argv)
{
	int arr[5];
	arr[0] = 3;
	arr[1] = 6;
	arr[2] = 15;
	arr[3] = 0;
	arr[4] = 3;

	ft_putnbr_fd(smaller(arr[2], arr[1]), 1);

}