#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0;i < (int)(n);i++)
#define RREP(i,n) for(int i = (int)n-1;i >= 0;i--)
#define FOR(i,s,n) for(int i = s;i < (int)n;i++)
#define RFOR(i,s,n) for(int i = (int)n-1;i >= s;i--)
#define ALL(a) a.begin(),a.end()
#define IN(a, x, b) (a<=x && x<b)
#define BIT(S,i) ((S&(1ll<<i))>0)
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a = b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a = b;return true;}return false;}
constexpr long long INF = 1e18;

signed main(){
	int N;
	cin>>N;
	vector<vector<int>>g(N);
	REP(i,N-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	auto dfs = [&](auto&&f,int now,int par)->int{
		int ret = 0;
		for(auto e:g[now]){
			if(e == par)continue;
			ret ^= (1 + f(f,e,now));
		}
		return ret;
	};
	if(dfs(dfs,0,-1))cout<<"Alice"<<endl;
	else cout<<"Bob"<<endl;
}