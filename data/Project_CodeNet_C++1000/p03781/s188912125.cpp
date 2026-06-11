#include <bits/stdc++.h>

int main()
{
	int n;
	scanf("%d",&n);

	for(int i = 1 ; ; i++)
	{
		if( i*(i + 1) >= 2*n )
		{
			printf("%d\n",i);
			return 0;
		}
	}
}