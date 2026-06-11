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
	vector<vector<int>> road(N);
	vector<bool> used(N, false);
	REP(i, N-1){
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		road[a].push_back(b);
		road[b].push_back(a);
	}
	int f=1;
	int s=1;
	queue<PII> que;
	que.push({0, 0});
	que.push({N-1, 1});
	while(!que.empty()){
		PII d = que.front();
		que.pop();
		if(d.second==0){
			++f;
		}else{
			++s;
		}
		foreach(i, road[d.first]){
			if(used[i])continue;
			que.push({i, d.second});
			used[i]=true;
		}
	}
	if(f>s){
		cout << "Fennec" << endl;
	}else{
		cout << "Snuke" << endl;
	}
	return 0;
}
