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
	int x;
	cin >> N >> x;
	if(x==1||x==2*N-1){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	if(N==2){
		REPA(i, 4){
			cout << i << endl;
		}
		return 0;
	}
	set<int> s;
	vector<int> ans;
	if(x==2){
		ans.push_back(3);
		ans.push_back(2);
		ans.push_back(1);
		ans.push_back(4);
	}else{
		ans.push_back(x-1);
		ans.push_back(x);
		ans.push_back(x+1);
		ans.push_back(x-2);
	}
	REPA(i, 2*N)s.insert(i);
	foreach(i, ans)s.erase(i);
	int count = 0;
	foreach(i, s){
		cout << i << endl;
		if(++count == N - 2){
			foreach(j, ans)cout << j << endl;
		}
	}

	return 0;
}
