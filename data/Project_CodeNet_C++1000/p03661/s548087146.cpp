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
int N;
int a[200000];
void solve(){
	ll g = 0;
	reps(i, N - 1)
		g += a[i];
	ll h = a[0];
	ll ans = abs(h - g);
	reps(i, N - 2){
		h += a[i];
		g -= a[i];
		chmin(ans, abs(h - g));
	}
	cout << ans << endl;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N;
	rep(i, N) {
		cin >> a[i];
	}
		solve();
	return 0;
}
