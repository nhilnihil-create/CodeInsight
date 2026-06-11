#include <stdio.h>
int main()
{
   int count=0, n, o =0;
   scanf("%d", &n);
   while (count <= n)
   {
	o=o+count;
	count++;
   }
   printf("%d", o);
   return 0;
}