#include<cstdio>
using namespace std;

const int MAXN = 100010;

int a[MAXN];

int main(){
	int N, L;
	scanf("%d %d", &N, &L);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &a[i]);
	int p = 1;
	while (p < N){
		if (a[p] + a[p + 1] >= L)
			break;
		++p;
	}
	if (p == N){
		printf("Impossible");
		return 0;
	}
	printf("Possible\n");
	for (int i = 1; i < p; ++i)
		printf("%d\n", i);
	for (int i = N - 1; i > p; --i)
		printf("%d\n", i);
	printf("%d", p);
	return 0;
}
