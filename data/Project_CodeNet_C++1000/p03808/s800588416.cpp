#include<cstdio>
using ll = long long;

int main(){
	ll N;
	scanf("%lld", &N);
	ll triangle = N*(N + 1) >> 1, sum = 0;
	int a[N];
	for (int i = 0; i < N; ++i){
		scanf("%d", a + i);
		sum += a[i];
	}
	if(sum % triangle){
		printf("NO\n");
		return 0;
	}
	ll sousa = sum/triangle;
	for (int i = 0; i < N; ++i){
		if(sousa + a[i] - a[(i + 1) % N] < 0 || (sousa + a[i] - a[(i + 1) % N]) % N){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}