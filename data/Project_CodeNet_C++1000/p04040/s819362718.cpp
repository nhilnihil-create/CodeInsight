#include<bits/stdc++.h>
#define LL long long
#define REP(i,n) for(int i=0;i<(n);++i)
#define PER(i,n) for(int i=n-1;i>=0;--i)
#define REPA(i,n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define PII pair<int,int>
#define PLI pair<long long, int>
#define PLL pair<long long, long long>
#define MOD ((LL)1e9+7) 
#define INF ((LL)1e9+7)
#define INFLL ((LL)1e18)
#define ALL(x) (x).begin(),(x).end()
#define BIT(x) (1LL << (x))
using namespace std;
template<class t, class u> bool chmax(t &a, u b){if(a<b){a=b;return true;}return false;}
template<class t, class u> bool chmin(t &a, u b){if(a>b){a=b;return true;}return false;}

LL modpow(LL x, LL b){
	LL res = 1;
	while(b){
		if(b&1)res = res * x % MOD;
		x = x * x % MOD;
		b>>=1;
	}
	return res;
}

LL modinv(LL x){
	return modpow(x, MOD-2);
}

LL factorial(LL x){
	static vector<LL> memo((int)2e5, 0);
	memo[1]=1;
	if(x<=1)return 1;
	if(memo[x]>=1)return memo[x];
	int i;
	for(i=memo.size()-1;!memo[i];--i);
	LL res = memo[i];
	for(i=i+1;i<=x;++i){
		res *= i;
		res %= MOD;
		memo[i] = res;
	}
	return memo[x];
}


LL C(LL a, LL b){
	return factorial(a) * modinv(factorial(b) * factorial(a-b) % MOD) % MOD;
}

LL H(LL a, LL b){
	return C(a+b, b);
}

int main(){
	LL h, w, a, b;
	cin >> h >> w >> a >> b;
	LL ans = 0;
	for(int x = b+1;x<=w;++x){
		ans += H(x-1, h-a-1) * H(w-x, a-1);
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
