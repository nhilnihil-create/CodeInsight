#include <stdio.h>
int N,K,X,Y;
int main()
{
	scanf("%d",&N);
	scanf("%d",&K);
	scanf("%d",&X);
	scanf("%d",&Y);

	if (N<=K)
	{
		printf("%d",X*N);
	}
	else
	{
		printf ("%d",X*K+Y*(N-K));
	}
}