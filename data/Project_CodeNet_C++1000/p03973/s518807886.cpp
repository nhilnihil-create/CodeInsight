#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0;i < (int)(n);i++)
#define RREP(i,n) for(int i = (int)n-1;i >= 0;i--)
#define FOR(i,s,n) for(int i = s;i < (int)n;i++)
#define RFOR(i,s,n) for(int i = (int)n-1;i >= s;i--)
#define ALL(a) a.begin(),a.end()
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a = b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a = b;return true;}return false;}
constexpr long long INF = 1e18;

signed main(){
	int N;
	cin >> N;
	vector<int>a(N);
	REP(i,N){
		cin >> a[i];
	}
	int lim = 2,ans = a[0]-1;
	FOR(i,1,N){
		ans+=(a[i]-1)/lim;
		if(lim==a[i])lim++;
	}
	cout << ans << endl;
}