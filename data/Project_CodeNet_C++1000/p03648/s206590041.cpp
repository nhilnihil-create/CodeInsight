#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int K; cin >> K;

	int N = 50;

	vector<int>v(N, N - 1 + K / N);

	K %= N;
	rep(i, 0, K) {
		sort(all(v));
		v[0] += N;
		rep(j, 1, v.size())v[j]--;
	}
	cout << N << endl;
	rep(i, 0, v.size())cout << v[i] << (i == v.size() - 1 ? '\n' : ' ');
	return 0;
}