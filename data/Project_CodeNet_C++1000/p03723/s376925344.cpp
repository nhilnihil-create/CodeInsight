#include<stdio.h>
int main()
{
	int a,b,c,count,x,y,z;
	while(~scanf("%d %d %d", &a, &b, &c))
	{
		count = 0;
		if(!(a%2) && a==b && b==c)
			printf("-1\n");
		else
		{
			while( !(a%2) && !(b%2) && !(c%2))
			{
				count++;
				x = (b+c)/2;
				y = (a+c)/2;
				z = (a+b)/2;
				a = x;
				b = y;
				c = z;
			}
			printf("%d\n", count);
		}
	}
	return 0;
}