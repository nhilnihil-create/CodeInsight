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

int mx[]={0, 1, 1, 1, 0, -1, -1, -1, 0}, my[]={0, 1, 0, -1, -1, -1, 0, 1, 1};

int main(){
	LL h, w, n;
	cin >> h >> w >> n;
	vector<LL> ans(10, 0);
	ans[0] = (h-2)*(w-2);
	set<PLL> s;
	REP(i, n){
		PLL d;
		cin >> d.first >> d.second;
		s.insert(d);
	}
	set<PLL> used;
	foreach(i, s){
		REP(j, 9){
			LL ny = i.first + my[j];
			LL nx = i.second + mx[j];
			if(nx<=1||nx>=w||ny<=1||ny>=h)continue;
			if(used.count(PLL(ny, nx)))continue;
			used.insert(PLL(ny, nx));
			int count = 0;
			REP(k, 9)count += s.count(PLL(ny + my[k], nx + mx[k]));
			++ans[count];
			--ans[0];
		}
	}
	foreach(i, ans)cout << i << endl;
}
