#include <stdlib.h>
#include <stdio.h>

int	count_digits(long n)
{
	int counter;

	if (n == 0)
		return (1);
	counter = 0;
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char *ft_itoa(int n)
{
	char	*res;
	int		len;
	int		pos;
	long	num;

	num = n;
	pos = num >= 0;
	len = count_digits(num) + (!pos ? 1 : 0);
	num *= pos ? 1 : -1;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	while (len >= 0)
	{
		res[len - 1] = num % 10 + 48;
		num /= 10;
		len--;
	}
	if (!pos)
		res[0] = '-';
	return (res);
}

int getSumDigits(int num)
{
  int res = 0;

  for (char *str = ft_itoa(num); *str; str++)
    res += *str - '0';

  return (res);
}

int multiplyAndCompare(int num, int sum)
{
  int tmp;

  for (int i = 2; i < 10; i++)
  {
    tmp = getSumDigits(num * i);
    if (tmp != sum)
      return (1);
  }

  return (0);
}

int main (void)
{
  int sum;

  printf("This numbers digits sum does not change when multiply:\n");

  for (int num = 10; num < 100; num++)
  {
    sum = getSumDigits(num);
    if (!multiplyAndCompare(num, sum))
      printf("%d\n", num);
  }
}