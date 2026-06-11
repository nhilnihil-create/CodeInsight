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

int dp[100010][101];

signed main(){
	int N;
	cin>>N;
	map<int,int>mp;
	vector<int> x(N);
	REP(i,N){
		int t;
		cin >> t;
		x[i] = t;
		mp[t] = i;
	}
	int L,Q;
	cin>>L>>Q;
	REP(i,N)dp[i][0] = upper_bound(ALL(x),x[i]+L) - 1 - x.begin();
	REP(j,100)REP(i,N)dp[i][j+1] = dp[dp[i][j]][j];
	auto f =[&](int x,int now){
		RREP(i,60)if((x>>i)&1)now = dp[now][i];
		return now;
	};
	vector<int>ans;
	REP(i,Q){
		int a,b;
		cin>>a>>b;
		a--;b--;
		if(b < a)swap(a,b);
		int l = -1, r = N + 1;
		while(r - l > 1){
			int c = (l + r) / 2;
			if(f(c,a)>=b) r = c;
			else l = c;
		}
		ans.push_back(r);
	}
	for(auto e:ans)cout<<e<<endl;
}
