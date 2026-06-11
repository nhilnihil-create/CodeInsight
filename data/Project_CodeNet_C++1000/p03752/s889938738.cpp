#include "bits/stdc++.h"
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0;i < (int)(n);++i)
#define RREP(i,n) for(int i = (int)n-1;i >= 0;--i)
#define FOR(i,s,n) for(int i = s;i < (int)n;++i)
#define RFOR(i,s,n) for(int i = (int)n-1;i >= s;--i)
#define ALL(a) a.begin(),a.end()
#define IN(a, x, b) (a<=x && x<b)
template<class T>inline void out(T t){cout<<t<<"\n";}
template<class T,class... Ts>inline void out(T t,Ts... ts){cout<<t<<" ";out(ts...);}
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a = b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a = b;return true;}return false;}
constexpr int INF = 1e18;

signed main(){
	int N,K;
	cin >> N >> K;
	vector<int>a(N);
	REP(i,N){
		cin >> a[i];
	}
	int ans = INF;
	REP(i,1ll << N){
		if(__builtin_popcountll(i) != K)continue;
		int now = 0;
		int cost = 0;
		REP(j,N){
			if(i & (1ll << j)){
				cost += max(0ll,now - a[j] + 1);
				now = max(a[j],now + 1);
			}else{
				if(now >= a[j])continue;
				cost += a[j] - now;
				now = max(now,a[j]);
			}
		}
		CHMIN(ans,cost);
	}
	cout << ans << endl;
}