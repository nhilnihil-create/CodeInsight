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

	int w,h,n;
	cin >> w >> h >> n;
	int a1 = 0;
	int a2 = w;
	int a3 = 0;
	int a4 = h;
	rep(i,n){
		int x,y,a;
		cin >> x >> y >> a;
		if(a == 1)chmax(a1,x);
		if(a == 2)chmin(a2,x);
		if(a == 3)chmax(a3,y);
		if(a == 4)chmin(a4,y);
	}
	if(a1 < a2 && a3 < a4){
		cout << (a2-a1)*(a4-a3) << endl;
	}else{
		cout << 0 << endl;
	}

	return 0;
}
/*----------------------------------------------------------------*/

// g++ -std=gnu++17 code1.cpp
// sudo pip3 install --upgrade online-judge-tools
// rm -r -f test;oj dl https://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_b
// rm -r -f test;oj dl https://abc047.contest.atcoder.jp/tasks/abc047_b