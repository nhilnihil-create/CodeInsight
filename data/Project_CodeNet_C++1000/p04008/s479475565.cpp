#include "bits/stdc++.h"
using namespace std;
#define int long long
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define RREP(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define FOR(i, s, n) for (int i = s; i < (int)n; ++i)
#define RFOR(i, s, n) for (int i = (int)n - 1; i >= s; --i)
#define ALL(a) a.begin(), a.end()
#define IN(a, x, b) (a <= x && x < b)
template<class T>inline void out(T t){cout << t << "\n";}
template<class T,class... Ts>inline void out(T t,Ts... ts){cout << t << " ";out(ts...);}
template<class T>inline bool CHMIN(T&a,T b){if(a > b){a = b;return true;}return false;}
template<class T>inline bool CHMAX(T&a,T b){if(a < b){a = b;return true;}return false;}
constexpr int INF = 1e18;


signed main(){
	int N,K;
	cin >> N >> K;
	vector<int>a(N);
	vector<vector<int>>g(N);
	int ans = 0;
	REP(i,N){
		cin >> a[i];
		--a[i];
		if(i){
			g[a[i]].emplace_back(i);
		}else{
			ans += a[i] != 0;
		}
	}
	{
		auto dfs = [&](auto&&f,int now,int par) -> int {
			int height = 0;
			for(auto e:g[now]){
				if(e == par)continue;
				CHMAX(height,f(f,e,now));
			}
			if(now && height >= K - 1 && par != 0){
				++ans;
				height = -1;
			}
			return height + 1;
		};
		dfs(dfs,0,-1);
	}
	cout << ans << endl;
}