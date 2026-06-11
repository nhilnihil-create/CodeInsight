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

int main(){
	int N;
	cin >> N;
	vector<LL> L(N), R(N);
	vector<LL> low(N, INF), high(N, 0);
	foreach(i, L)cin>>i;
	foreach(i, R)cin>>i;
	low[0] = high[0] = L[0];
	LL lh = L[0];
	REPA(i, N){
		high[i] = L[i];
		if(lh==L[i]){
			low[i] = 1;
		}else{
			low[i] = L[i];
		}
		chmax(lh, L[i]);
	}
	if(R[N-1] < low[N-1] || high[N-1] < R[N-1]){
		cout << 0 << endl;
		return 0;
	}
	low[N-1] = high[N-1] = R[N-1];
	lh = R[N-1];
	PER(i, N-1){
		LL nlow;
		LL nhigh =R[i];
		if(lh == R[i]){
			nlow = 1;
		}else{
			nlow = nhigh = R[i];
		}
		if(high[i] < nlow || low[i] > nhigh){
			cout << 0 << endl;
			return 0;
		}
		chmax(low[i], nlow);
		chmin(high[i], nhigh);
		chmax(lh, R[i]);
	}
	LL ans = 1;
	REP(i, N){
		ans *= high[i] - low[i] + 1;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
