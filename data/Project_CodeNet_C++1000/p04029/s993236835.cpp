#include <stdio.h>
int main ()
{
	int num;
	scanf ("%d", &num);
	int hasil = 0;
	for (int i = 1; i <= num; i++)
	{
		hasil += i;
	}
printf ("%d", hasil);	
return 0;
}