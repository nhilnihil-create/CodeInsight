#include <cstdio>
#include <iostream>
#define ll long long
using std::min;

const int MAXN =2002;

inline int read(){
	int x =0; char c =getchar();
	while(c < '0' || c > '9') c =getchar();
	while(c >= '0' && c <= '9') x = (x<<3) + (x<<1) + (48^c), c =getchar();
	return x;
}

int n, x, c[MAXN];
int dp[MAXN][MAXN]/*得到第 i个，进化最多 j次，的消耗。不含进化消耗*/;

int main(){
	n =read(), x =read();
	for(int i =0; i < n; ++i) c[i] =read();
	for(int i =0; i < n; ++i) for(int j =0; j < n /*进化 n次一定不优*/; ++j){
		if(j == 0){
			dp[i][j] =c[i];
			continue;
		}
		int d =i-j;
		if(d < 0) d +=n;
		dp[i][j] =min(dp[i][j-1], c[d]);
	}
	
	ll ans =0x4fffffffffffffff;
	for(int j =0; j < n; ++j){
		ll ans2 =1ll*j*x;
		for(int i =0; i < n; ++i) ans2 +=dp[i][j];
		ans =min(ans, ans2);
	}
	printf("%lld", ans);
}