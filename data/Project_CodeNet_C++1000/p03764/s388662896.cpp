#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	long long cnt_x = 0, cnt_y = 0, x[N], y[M];
	for(int i=0; i<N; i++){
		scanf("%lld", x+i);
		if(i > 0){
			int a = ((long long)i * (N-i)) % mod;
			cnt_x = (cnt_x + a * (x[i] - x[i-1])) % mod;
		}
	}
	for(int i=0; i<M; i++){
		scanf("%lld", y+i);
		if(i > 0){
			int a = ((long long)i * (M-i)) % mod;
			cnt_y = (cnt_y + a * (y[i] - y[i-1])) % mod;
		}
	}
	int ans = (cnt_x * cnt_y) % mod;
	printf("%d\n", ans);
	return 0;
}
