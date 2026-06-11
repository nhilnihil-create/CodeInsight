#include <stdio.h>

int N,A[303][303];

int main()
{
	scanf ("%d",&N);
	for (int i=0;i<N;i++) for (int j=0;j<N;j++) scanf("%d",&A[i][j]);

	long long ans = 0;
	for (int i=0;i<N;i++) for (int j=i+1;j<N;j++){
		bool g = 1;
		for (int k=0;k<N;k++) if (i != k && j != k){
			if (A[i][j] > A[i][k] + A[k][j]){
				puts("-1");
				return 0;
			}
			else if (A[i][j] == A[i][k] + A[k][j]){
				g = 0;
				break;
			}
		}
		if (g)
			ans += A[i][j];
	}
	printf ("%lld\n",ans);

	return 0;
}