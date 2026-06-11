#include <bits/stdc++.h>

#define lld long long
#define pp pair<int,int>
#define pb push_back
#define MOD 1000000007
#define left lleft
#define right rright
#define INF 2000000000
#define Linf 1000000000000000000LL
#define next nnext
#define minus mminus

using namespace std;

lld N;
lld d[1000002],sum[1000002];

int main(){
	scanf("%lld",&N);
	d[1] = sum[1] = N;
	for(int i=2; i<=N; i++){
		d[i] = d[i-1];
		lld t = max(2,i-1);
		d[i] += (N-t+1)*N;
		if(t > 2){
			d[i] += sum[i-3];
			d[i] += (t-2)*(N-1);
		}
		sum[i] = sum[i-1]+d[i];
		d[i] %= MOD; sum[i] %= MOD;
	}
	printf("%lld\n",d[N]);

	return 0;
}
