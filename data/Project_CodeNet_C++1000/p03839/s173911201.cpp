#include<cstdio>
using ll = long long;

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	ll a[N], ruiseki[N + 1], absruiseki[N + 1];
	ruiseki[0] = absruiseki[0] = 0;
	for (int i = 0; i < N; ++i){
		scanf("%lld", a + i);
		ruiseki[i + 1] = ruiseki[i] + a[i];
		absruiseki[i + 1] = absruiseki[i] + (a[i] > 0 ? a[i] : 0);
	}
	ll answer = 0;
	for (int i = 0; i < N - K + 1; ++i){
		if(answer < (ruiseki[i + K] - ruiseki[i] > 0 ? ruiseki[i + K] - ruiseki[i] : 0) + absruiseki[N] - absruiseki[i + K] + absruiseki[i]) answer = (ruiseki[i + K] - ruiseki[i] > 0 ? ruiseki[i + K] - ruiseki[i] : 0) + absruiseki[N] - absruiseki[i + K] + absruiseki[i];
	}
	printf("%lld\n", answer);
	return 0;
}