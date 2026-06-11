#include <bits/stdc++.h>
#ifdef _WIN32
#include "debug.hpp"
#endif
using namespace std;

#define rep(i, N)  for(int i = 0; i < (N); i++)
#define reps(i, N) for(int i = 1; i <= (N); i++)
#define repr(i, N) for(int i = (N) - 1; i >= 0; i--)
#define pub push_back

template<typename T> 
void chmax(T &a, T b){ a = max(a, b); };
template<typename T> 
void chmin(T &a, T b){ a = min(a, b); };

typedef long long ll;
typedef pair<int, int> P;
const int INF = 100000000;
const ll LINF = 10000000000000000;
const int MOD = 1000000007;
const int dx[9] = { 0, 1,  0, -1, 1,  1, -1, -1, 0};
const int dy[9] = { 1, 0, -1,  0, 1, -1, -1,  1, 0};
//--------------------------------------//
int n, m;
ll x[100000], y[100000];

ll xs[100000];
ll sy;
void solve(){
	ll ans = 0;
	rep(i, n - 1)
		xs[i] = ((x[i + 1] - x[i]) * (i + 1) * (n - i - 1)) % MOD;
	rep(i, m - 1)
		sy = (sy + (y[i + 1] - y[i]) * (i + 1) * (m - i - 1)) % MOD;
	rep(i, n - 1)
		ans = (ans + xs[i] * sy) % MOD;
	cout<<ans<<endl;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n)
		cin >> x[i];
	rep(i, m)
		cin >> y[i];
	solve();
	return 0;
}
