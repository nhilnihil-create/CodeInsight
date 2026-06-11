#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MOD = 1e9 + 7 , MAXN = 4e6;
int dp[2010][2010] , N , K , jc[MAXN + 10] , ny[MAXN + 10];

inline int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1)
			times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

inline void init(){
	jc[0] = 1;
	for(int i = 1 ; i <= MAXN ; ++i)
		jc[i] = 1ll * jc[i - 1] * i % MOD;
	ny[MAXN] = poww(jc[MAXN] , MOD - 2);
	for(int i = MAXN - 1 ; i >= 0 ; --i)
		ny[i] = 1ll * ny[i + 1] * (i + 1) % MOD;
}

int main(){
	init();
	N = read();
	K = read();
	if(K == 1){
		puts("1");
		return 0;
	}
	init();
	for(int i = 1 ; i <= N ; ++i){
		dp[i][0] = 1;
		for(int j = 1 ; j <= i ; ++j){
			int t = N * K - i - (j - 1) * (K - 1) - 1;
			dp[i][j] = (dp[i - 1][j] + 1ll * dp[i][j - 1] * jc[t] % MOD * ny[K - 2] % MOD * ny[t - K + 2] % MOD * (N - j + 1) % MOD) % MOD;
		}
	}
	cout << dp[N][N];
	return 0;
}
