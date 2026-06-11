#include <stdio.h>
#include <string>

void go(int N, int n)
{
	if (n == 0) return;
	if (N >= n){
		go(N-n,n-1);
		printf ("%d\n",n);
	}
	else go(N,n-1);
}

int main()
{
	int N;

	scanf ("%d",&N);

	int n = 1, s = 0;
	while (N > s + n){
		s += n;
		n++;
	}

	go(N,n);
	return 0;
}