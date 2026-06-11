#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define int ll
typedef pair<int,int> pii;
#define fi first
#define se second
#define Sort(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/4
#define INTINF INT_MAX/2
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T &a, T b){if(a < b){a = b;return true;}return false;}
template<class T> inline bool chmin(T &a, T b){if(a > b){a = b;return true;}return false;}
/*----------------------------------------------------------------*/
// const int MOD = 998244353;
const int MOD = 1000000007;

/*----------------------------------------------------------------*/
signed main(){

	
	int n,m;
	cin >> n >> m;
	vll a(n),b(n);
	vll c(m),d(m);
	rep(i,n)cin >> a[i] >> b[i];
	rep(i,m)cin >> c[i] >> d[i];

	rep(i,n){
		int dist = INF;
		int res = 0;
		rep(j,m){
			if(chmin(dist,abs(a[i]-c[j]) + abs(b[i]-d[j])))res = j+1;
		}
		cout << res << endl;
	}



	return 0;
}
/*----------------------------------------------------------------*/

// g++ -std=gnu++17 code1.cpp
// sudo pip3 install --upgrade online-judge-tools
// rm -r -f test;oj dl https://code-festival-2018-quala.contest.atcoder.jp/tasks/code_festival_2018_quala_c
// rm -r -f test;oj dl https://abc057.contest.atcoder.jp/tasks/abc057_b