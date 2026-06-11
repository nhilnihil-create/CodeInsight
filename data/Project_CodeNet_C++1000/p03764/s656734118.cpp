#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 9999999999
#define m0(x) memset(x,0,sizeof(x))
//#define fill(x,y) memset(x,y,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long


using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int dxx[9] = { 0, 0,0,1,1,1,-1,-1,-1 };
int dyy[9] = { 0, 1,-1,0,1,-1,0,1,-1 };

const int MOD = 1e9 + 7;


int x[100010], y[100010];
signed main() {
	int N, M; cin >> N >> M;
	REP(i, N)cin >> x[i];
	REP(i, M)cin >> y[i];
	int res1 = 0, res2 = 0;
	REP(i, N) {
		res1 += (1 - N + 2 * i)*x[i] % MOD;
		res1 %= MOD;
	}
	REP(i, M) {
		res2 += (1 - M + 2 * i)*y[i] % MOD;
		res2 %= MOD;
	}
	ll ans = res1 * res2%MOD;
	print(ans);
}


