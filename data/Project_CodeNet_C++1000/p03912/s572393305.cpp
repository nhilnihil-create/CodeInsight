#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define RFOR(i, s, n) for (int i = (n) - 1; i >= (s); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define ALL(a) a.begin(), a.end()
const long long MOD = 1e9 + 7, INF = 1e18;
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a=b;return true;}return false;}



signed main(){
	int N,M;
	cin>>N>>M;
	vector<int>cnt(100010,0);
	vector<int>mod(M,0);
	vector<int>pair(M,0);
	REP(i,N){
		int t;
		cin >> t;
		cnt[t]++;
		mod[t%M]++;
	}
	REP(i,100010)pair[i%M] += cnt[i] / 2 * 2;
	int ans = mod[0] / 2;
	FOR(i,1,M/2+1){
		if(i==M-i){
			ans += mod[i] / 2;
		}else{
			int t = min(mod[i],mod[M-i]);
			ans += t;
			ans += max(0ll,min(mod[i] - t,pair[i]) / 2);
			ans += max(0ll,min(mod[M-i] - t,pair[M-i]) / 2);
		}
	}
	cout << ans << endl;
}
