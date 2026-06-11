#include <bits/stdc++.h>

using namespace std;

const int maxn = 2007;
const int maxm = 4e6 + 7;
const int mod = 1e9 + 7;

int n;
int K;
int f[maxn][maxn];
int fac[maxm];
int inv[maxm];

int Add(int x,int y){return (x += y) >= mod ? x - mod : x;}
int Sub(int x,int y){return (x -= y) <    0 ? x + mod : x;}
int Mul(int x,int y){return 1LL * x * y % mod;}
int Pow(int x,int k,int re = 1){
	for(; k; k >>= 1,x = Mul(x,x))
		if(k & 1)re = Mul(re,x);
	return re;
}
int C(int n,int m){
	if(n < m || m < 0)return 0;
	return Mul(fac[n],Mul(inv[m],inv[n - m]));
}
int main(){
	cin >> n >> K;
	if(K == 1){
		puts("1");
		return 0;
	}
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= n * K; ++i)
		fac[i] = Mul(fac[i - 1],i);
	inv[n * K] = Pow(fac[n * K],mod - 2);
	for(int i = n * K - 1; i; --i)
		inv[i] = Mul(inv[i + 1],i + 1);
	f[1][0] = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= i; ++j){
			//printf("%d %d %d\n",i,j,f[i][j]);
			f[i + 1][j] = Add(f[i + 1][j],f[i][j]);
			if(j + 1 <= n)f[i][j + 1] = Add(f[i][j + 1],Mul(f[i][j],Mul(n - j,C(n * K - j * (K - 1) - i - 1,K - 2))));
		}
	}
	printf("%d\n",f[n][n]);
	return 0;
}
