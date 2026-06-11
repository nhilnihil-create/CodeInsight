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

int N;
vector<LL> line;

bool check(int x){
	LL sum = line[x];
	REP(i, N){
		if(x==i)continue;
		if(sum*2 < line[i])return false;
		sum += line[i];
	}
	return true;
}

int main(){
	int N;
	cin >> N;
	LL A, B, C, D;
	cin >> A >> B >> C >> D;
	--N;
	LL dis = abs(B - A);
	LL lo = 0;
	LL ho = 0;
	LL d = dis / D;
	dis -= d * D;
	N -= d;
	if(N<0){
		cout << "NO" << endl;
		return 0;
	}
	lo = (C-D) * d;
	ho += N / 2 * (D-C);
	lo -= N / 2 * (D-C);
	N %= 2;
	if(N){
		if((lo + C <= dis && dis <= ho + D) || (lo - D <= dis && dis <= ho - C)){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	else{
		if(lo <= dis && dis <= ho){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}

	return 0;
}
