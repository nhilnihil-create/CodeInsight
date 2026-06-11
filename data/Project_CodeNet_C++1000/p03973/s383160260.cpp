#include <stdio.h>

int main()
{
	int N,L=1; long long A = 0;
	scanf ("%d",&N);
	for (int i=0;i<N;i++){
		int x; scanf ("%d",&x);
		if (x < L) continue;
		if (x == L) L++;
		else{
			A += (x - 1) / L;
			if (L == 1) L = 2;
		}
	}
	printf ("%lld\n",A);

	return 0;
}