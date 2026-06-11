#include <stdio.h>

int N,P[100100];

int main()
{
	scanf ("%d",&N);
	int a = 0, l = 0;
	for (int i=1;i<=N;i++){
		int p; scanf ("%d",&p);
		if (i != p) a += (l + 1) / 2, l = 0;
		else l++;
	}
	a += (l + 1) / 2;
	printf ("%d\n",a);

	return 0;
}